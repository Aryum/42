#include	<string.h>
#include	<stdio.h>
#include 	<stdlib.h>

char *createstr(char *c)
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
} t_strcatcpy_tst;


t_strcatcpy_tst strcatcpy_createTestParams_Alloc(char* dst,char* src, size_t size, char *name)
{
	t_strcatcpy_tst retval;
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

//not used for cpy since it is undefined behaviour left because it might be useful

t_strcatcpy_tst strcatcpy_createTestParams_SameStr(char* str, int index1,int index2, size_t size, char *name)
{
	t_strcatcpy_tst retval;	
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

void freeAlloc(t_strcatcpy_tst tst)
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
typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

t_strcmp_ret strComp(char *a,char *b)
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

int strcatcpy_comparefunctions(t_strcatcpy_tst test, size_t(*baseFunc)(char *, const char *, size_t), size_t(*myFunc)(char *, const char *, size_t), int printAll)
{
	int retVal = 1;

	t_strcatcpy_tst basetest;
	t_strcatcpy_tst mytest;
	if(!test.sameStr)
	{
		basetest = strcatcpy_createTestParams_Alloc(test.dst_mod, test.src, test.size,test.name);
		mytest = strcatcpy_createTestParams_Alloc(test.dst_mod, test.src, test.size,test.name);
	}
	else
	{
		//not used for cpy since it is undefined behaviour left because it might be useful
		basetest = strcatcpy_createTestParams_SameStr(test.dst_mod, test.index1,test.index2, test.size,test.name);
		mytest =  strcatcpy_createTestParams_SameStr(test.dst_mod, test.index1,test.index2, test.size,test.name);

	}

	size_t base_len = baseFunc(basetest.dst_mod, basetest.src, basetest.size);
	size_t my_len = myFunc(mytest.dst_mod, mytest.src, mytest.size);

	t_strcmp_ret cmp_result = strComp(mytest.dst_mod,basetest.dst_mod);
	int sucess = cmp_result.sucess && base_len == my_len;
	if(!(sucess) || printAll)
	{
		if(!sucess)
		{
			retVal = 0;
			if(!cmp_result.sucess)
				printf("	Failed at index (%d)\n", cmp_result.index);
			else
				printf("	Failed at length \n");
		}
		else
			printf("	Passed\n");

		printf("		Source	%s\n", nullcheck(test.src) );
		printf("		Dst Og	%s\n", nullcheck(test.dst_og));
		printf("		Length	%ld\n",test.size);

		//not used for cpy but might be useful in the future
		if(test.sameStr)
		{
			printf("		1st Index	%d\n", test.index1);
			printf("		2nd Index	%d\n", test.index2);
		}
		printf("			Base\n");
		printf("				string %s\n", nullcheck(basetest.dst_mod) );
		printf("				return Val %ld\n", base_len);
		
		printf("			Mine\n");
		printf("				string %s\n", nullcheck(mytest.dst_mod) );
		printf("				return Val %ld\n", my_len);
		
	}

	freeAlloc(basetest);
	freeAlloc(mytest);
	return (retVal);
}

void strcatcpy_logMessages(size_t(*baseFunc)(char *, const char *, size_t), size_t(*myFunc)(char *, const char *, size_t), int printAll)
{

	//create a test that src and dest are part of the same string
	t_strcatcpy_tst tests[] = 
	{ 	
		strcatcpy_createTestParams_Alloc("-----", "hello", 12,"Default behaviour"),
		strcatcpy_createTestParams_Alloc("-----", "hello", 9,"Size smaller total of strings"),
		strcatcpy_createTestParams_Alloc("-----", "hello", 3, "Size smaller than dest"),

		/*
		they are undefined
		strcatcpy_createTestParams_SameStr ("Hello",0,1, 6, "1 Src and dest are in the same string"),
		strcatcpy_createTestParams_SameStr ("Hello",1,0, 6, "2 Src and dest are in the same string"),
		strcatcpy_createTestParams_SameStr ("Hello",0,1, 3, "3 Src and dest are in the same string"),
		strcatcpy_createTestParams_SameStr ("Hello",1,0, 3, "4 Src and dest are in the same string"),
		*/

		strcatcpy_createTestParams_Alloc("","",0,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!strcatcpy_comparefunctions(tests[i],baseFunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		freeAlloc(tests[i]);
		i++;
	}
}
