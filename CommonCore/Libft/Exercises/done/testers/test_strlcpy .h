#include	<string.h>
#include	<stdio.h>
#include 	<stdlib.h>


typedef struct strlcpy_tests
{
	char* dst_mod;
	char* dst_og;
	char* src;
	size_t size;
	char *name;
	//not used for cpy since it is undefined behaviour left because it might be useful
	int index1;
	int index2;
	int sameStr;
	char *ptr;
} t_strlcpy_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

typedef struct strlcpy_result
{
	t_strlcpy_tst basetest;
	t_strlcpy_tst mytest;
	size_t base_len;
	size_t my_len;
	t_strcmp_ret cmp_result;

	int outresult;

} t_strlcpy_result;

static char *createstr(char *c)
{
	int size = strlen(c);
	char *alloc = (char *)malloc(size + 1);
	int i = 0;
	
	while(c[i] != '\0')
	{
		alloc[i] = c[i];
		i++;
	}
	alloc[i] = '\0';
	return alloc; 
}

static t_strlcpy_tst strlcpy_createTestParams_Alloc(char* dst,char* src, size_t size, char *name)
{
	t_strlcpy_tst retval;
	retval.name = name;
	retval.src = src;

	if(name != NULL)
	{
		retval.dst_mod = createstr(dst);
		retval.dst_mod = createstr(dst);
		retval.dst_og = createstr(dst);
	}
	retval.size = size;
	retval.sameStr = 0;
	return retval;
}

static t_strlcpy_tst strlcpy_createTestParams_SameStr(char* str, int index1,int index2, size_t size, char *name)
{
	t_strlcpy_tst retval;	
	retval.ptr = createstr(str);
	retval.name = name;
	retval.src = &(retval.ptr[index1]);
	retval.dst_mod = &(retval.ptr[index2]);
	retval.dst_og = createstr(&(str[index2]));
	retval.sameStr = 1;
	retval.size = size;
	retval.index1 = index1;
	retval.index2 = index2;

	return retval;
}

static void freeAlloc(t_strlcpy_tst tst)
{
	if(tst.name != NULL)
	{
		if(!tst.sameStr)
		{
			free(tst.dst_mod);
			free(tst.dst_og);
		}
		else
		{
			//not used for cpy since it is undefined behaviour left because it might be useful
			free(tst.ptr);
			free(tst.dst_og);
		}
	}
}

static t_strcmp_ret strComp(char *a,char *b)
{
	t_strcmp_ret retVal;
	int i = 0;
	while ((a[i] != '\0' || b[i] != '\0')) 
	{
		if(a[i] != b[i])
		{
			retVal.index = i;
			retVal.sucess = 0;
			return retVal;
		}
		i++;
	}		
	retVal.sucess = 1;
	retVal.index = 0;
	return retVal;
}

static char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}

static t_strlcpy_result strlcpy_comparefunctions(t_strlcpy_tst test, size_t(*baseFunc)(char *, const char *, size_t), size_t(*myFunc)(char *, const char *, size_t))
{
	t_strlcpy_result retVal;

	if(!test.sameStr)
	{
		retVal.basetest = strlcpy_createTestParams_Alloc(test.dst_mod, test.src, test.size,test.name);
		retVal.mytest = strlcpy_createTestParams_Alloc(test.dst_mod, test.src, test.size,test.name);
	}
	else
	{
		//not used for cpy since it is undefined behaviour left because it might be useful
		retVal.basetest = strlcpy_createTestParams_SameStr(test.dst_mod, test.index1,test.index2, test.size,test.name);
		retVal.mytest =  strlcpy_createTestParams_SameStr(test.dst_mod, test.index1,test.index2, test.size,test.name);

	}

	retVal.base_len = baseFunc(retVal.basetest.dst_mod, retVal.basetest.src, retVal.basetest.size);
	retVal.my_len = myFunc(retVal.mytest.dst_mod, retVal.mytest.src, retVal.mytest.size);

	retVal.cmp_result = strComp(retVal.mytest.dst_mod, retVal.basetest.dst_mod);
	retVal.outresult = retVal.cmp_result.sucess && retVal.base_len == retVal.my_len;

	return (retVal);
}

static void printresult(t_strlcpy_tst test,t_strlcpy_result res, int printAll)
{
	if(!(res.outresult) || printAll)
	{
		if(!res.outresult)
		{
			if(!res.cmp_result.sucess)
				printf("	Failed at index (%d)\n", res.cmp_result.index);
			else
				printf("	Failed at length \n");
		}
		else
			printf("	Passed\n");

		printf("		Source	%s\n", nullcheck(test.src) );
		printf("		Dst Og	%s\n", nullcheck(test.dst_og));
		//not used for cpy but might be useful in the future
		if(test.sameStr)
		{
			printf("		1st Index	%d\n", test.index1);
			printf("		2nd Index	%d\n", test.index2);
		}
		printf("			Base\n");
		printf("				string %s\n", nullcheck(res.basetest.dst_mod) );
		printf("				return Val %ld\n", res.base_len);
		
		printf("			Mine\n");
		printf("				string %s\n", nullcheck(res.mytest.dst_mod) );
		printf("				return Val %ld\n", res.my_len);
		
	}

	freeAlloc(res.basetest);
	freeAlloc(res.mytest);
}

int strlcpy_logMessages(size_t(*baseFunc)(char *, const char *, size_t), size_t(*myFunc)(char *, const char *, size_t), int printAll)
{

	//create a test that src and dest are part of the same string
	t_strlcpy_tst tests[] = 
	{ 	
		strlcpy_createTestParams_Alloc("-----", "hello",6,"Default behaviour"),
		strlcpy_createTestParams_Alloc("-----", "hello",5,"Size smaller than strings"),
		strlcpy_createTestParams_Alloc("---", "hello", 6,"Dst size Size smaller than both"),
		strlcpy_createTestParams_Alloc("---", "hello", 5,"Dst size and Size smaller src"),
		strlcpy_createTestParams_Alloc("-----", "hel", 6,"Src size smaller than both"),
		strlcpy_createTestParams_Alloc("-----", "hel", 5,"Src size and Size smaller than dst"),
		/*
		they are undefined
		strlcpy_createTestParams_SameStr ("Hello",0,1, 6, "1 Src and dest are in the same string"),
		strlcpy_createTestParams_SameStr ("Hello",1,0, 6, "2 Src and dest are in the same string"),
		strlcpy_createTestParams_SameStr ("Hello",0,1, 3, "3 Src and dest are in the same string"),
		strlcpy_createTestParams_SameStr ("Hello",1,0, 3, "4 Src and dest are in the same string"),
		*/

		strlcpy_createTestParams_Alloc("","",0,NULL)
	};
	int i = 0;
	int ret = 1; 
	while (tests[i].name != NULL)
	{
		t_strlcpy_result current = strlcpy_comparefunctions(tests[i],baseFunc, myFunc);
		if(ret == 1 && !current.outresult)
			ret = 0;
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		printresult(tests[i],current,printAll);
		if (!current.outresult)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		freeAlloc(tests[i]);
		i++;
	}
	return ret;
}
