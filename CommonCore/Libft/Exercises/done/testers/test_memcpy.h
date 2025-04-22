
#include	<string.h>
#include	<stdio.h>
#include 	<stdlib.h>

static char *createstr(char *c)
{
	int size = strlen(c);
	char *alloc = malloc(size + 1);
	int i = 0;
	
	while(c[i] != '\0')
	{
		alloc[i] = c[i];
		i++;
	}
	alloc[i] = '\0';
	return alloc; 
}

typedef struct memcpy_tests
{
	char *ptr;
	char* dst_new;
	char* dst_og;
	char* src;
	size_t size;
	char *name;
	int sameStr;
	int index1;
	int index2;


} t_memcpy_tst;

static t_memcpy_tst memcpy_createTestParams_Alloc(char* dst,char* src, size_t size, char *name)
{
	t_memcpy_tst retval;
	retval.name = name;
	retval.src = src;

	if(name != NULL)
	{
		retval.dst_new = createstr(dst);
		retval.dst_og = createstr(dst);
	}
	retval.size = size;
	retval.sameStr = 0;
	return retval;
}

static t_memcpy_tst memcpy_createTestParams_SameStr(char* str, int index1,int index2, size_t size, char *name)
{
	t_memcpy_tst retval;	
	retval.ptr = createstr(str);
	retval.name = name;
	retval.src = &(retval.ptr[index1]);
	retval.dst_new = &(retval.ptr[index2]);
	retval.dst_og = createstr(&(str[index2]));
	retval.sameStr = 1;
	retval.size = size;
	retval.index1 = index1;
	retval.index2 = index2;

	return retval;
}

static void freeAlloc(t_memcpy_tst tst)
{
	if(tst.name != NULL)
	{
		if(!tst.sameStr)
		{
			free(tst.dst_new);
			free(tst.dst_og);
		}
		else
		{
			free(tst.ptr);
			free(tst.dst_og);
		}
	}
}
typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

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

char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}

typedef struct memcpy_result
{
	t_memcpy_tst basetest;
	t_memcpy_tst mytest;
	t_strcmp_ret strcmp;
	int outResult;	
} t_memcpy_result; 

t_memcpy_result memcpy_comparefunctions(t_memcpy_tst test, void*(*baseFunc)(void *, const void *, size_t), void*(*myFunc)(void *, const void *, size_t))
{
	t_memcpy_result retVal;

	if(!test.sameStr)
	{
		retVal.basetest = memcpy_createTestParams_Alloc(test.dst_new, test.src, test.size,test.name);
		retVal.mytest = memcpy_createTestParams_Alloc(test.dst_new, test.src, test.size,test.name);
	}
	else
	{
		retVal.basetest = memcpy_createTestParams_SameStr(test.dst_new, test.index1,test.index2, test.size,test.name);
		retVal.mytest =  memcpy_createTestParams_SameStr(test.dst_new, test.index1,test.index2, test.size,test.name);
	}

	baseFunc(retVal.basetest.dst_new, retVal.basetest.src, retVal.basetest.size);
	myFunc(retVal.mytest.dst_new, retVal.mytest.src, retVal.mytest.size);

	retVal.strcmp  = strComp(retVal.mytest.dst_new, retVal.basetest.dst_new);
	retVal.outResult = retVal.strcmp.sucess; 

	return (retVal);
}

void printresult(t_memcpy_tst test,t_memcpy_result result, int printAll)
{
	if(!result.outResult || printAll)
	{
		if(!result.outResult)
			printf("	Failed at index (%d)\n", result.strcmp.index);
		else
			printf("	Passed\n");

		printf("		Source	%s\n", nullcheck(test.src) );
		printf("		Dst Og	%s\n", nullcheck(test.dst_og));
		if(test.sameStr)
		{
		printf("		1st Index	%d\n", test.index1);
		printf("		2nd Index	%d\n", test.index2);

		}
		printf("			Base\n");
		printf("				%s\n", nullcheck(result.basetest.dst_new) );
		printf("			Mine\n");
		printf("				%s\n", nullcheck(result.mytest.dst_new) );
		
	}

	freeAlloc(result.basetest);
	freeAlloc(result.mytest);
}

void memcpy_logMessages(void *(*baseFunc)(void *, const void *, size_t), void*(*myFunc)(void *, const void *, size_t), int printAll)
{

	//create a test that src and dest are part of the same string
	t_memcpy_tst tests[] = 
	{ 	
		memcpy_createTestParams_Alloc("-----", "hello",6,"Default behaviour"),
		memcpy_createTestParams_Alloc("-----", "hello",5,"Size smaller than strings"),
		memcpy_createTestParams_Alloc("---", "hello", 6,"Dst size Size smaller than both"),
		memcpy_createTestParams_Alloc("---", "hello", 5,"Dst size and Size smaller src"),
		memcpy_createTestParams_Alloc("-----", "hel", 6,"Src size smaller than both"),
		memcpy_createTestParams_Alloc("-----", "hel", 5,"Src size and Size smaller than dst"),
		/*
		they are undefined
		memcpy_createTestParams_SameStr ("Hello",0,1, 6, "1 Src and dest are in the same string"),
		memcpy_createTestParams_SameStr ("Hello",1,0, 6, "2 Src and dest are in the same string"),
		memcpy_createTestParams_SameStr ("Hello",0,1, 3, "3 Src and dest are in the same string"),
		memcpy_createTestParams_SameStr ("Hello",1,0, 3, "4 Src and dest are in the same string"),
		*/

		memcpy_createTestParams_Alloc("","",0,NULL)
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_memcpy_result current = memcpy_comparefunctions(tests[i],baseFunc, myFunc);
		if(ret == 1 && !current.outResult)
			ret = 0;
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printresult(tests[i],current,printAll);
			if (!current.outResult)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
			i++;
		} 
		freeAlloc(tests[i]);
	}
	return ret;
}
