#include	<string.h>
#include	<stdio.h>
#include 	<stdlib.h>

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
} t_memmove_tst;


static t_memmove_tst memmove_createTestParams_Alloc(char* dst,char* src, size_t size, char *name)
{
	t_memmove_tst retval;
	retval.name = name;
	retval.src = src;

	if(name != NULL)
	{
		if(dst != NULL )
		{
			retval.dst_mod = createstr(dst);
			retval.dst_og = createstr(dst);
		}
		else
		{
			retval.dst_mod = NULL;
			retval.dst_og = NULL;
		}
	}

	retval.size = size;
	retval.sameStr = 0;
	return retval;
}

static t_memmove_tst memmove_createTestParams_SameStr(char* str, int index1,int index2, size_t size, char *name)
{
	t_memmove_tst retval;	
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

static void freeAlloc(t_memmove_tst tst)
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

typedef struct memove_result
{
	t_memmove_tst basetest;
	t_memmove_tst mytest;
	size_t base_len;
	size_t my_len;
	t_strcmp_ret cmp_result;
	int outResult;
}	t_memove_result;

static t_memove_result memmove_comparefunctions(t_memmove_tst test, void*(*funcs[2])(void *, const void *, size_t ))
{
	t_memove_result retVal;

	
	if(!test.sameStr)
	{
		retVal.basetest = memmove_createTestParams_Alloc(test.dst_mod, test.src, test.size,test.name);
		retVal.mytest = memmove_createTestParams_Alloc(test.dst_mod, test.src, test.size,test.name);
	}
	else
	{
		//not used for cpy since it is undefined behaviour left because it might be useful
		retVal.basetest = memmove_createTestParams_SameStr(test.dst_mod, test.index1,test.index2, test.size,test.name);
		retVal.mytest =  memmove_createTestParams_SameStr(test.dst_mod, test.index1,test.index2, test.size,test.name);

	}
	funcs[0](retVal.basetest.dst_mod, retVal.basetest.src, retVal.basetest.size);

	funcs[1](retVal.mytest.dst_mod, retVal.mytest.src, retVal.mytest.size);
	retVal.base_len = strlen(retVal.basetest.dst_mod); 
	retVal.my_len = strlen(retVal.mytest.dst_mod);
	retVal.cmp_result = strComp(retVal.mytest.dst_mod,retVal.basetest.dst_mod);
	retVal.outResult = retVal.cmp_result.sucess && retVal.base_len == retVal.my_len;
	
	return (retVal);
}

static void printResult(t_memmove_tst test, t_memove_result res,int printAll)
{
	if(!(res.outResult) || printAll)
	{
		if(!res.outResult)
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
		printf("		Length	%ld\n",test.size);

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
void memmove_logMessages(void*(*funcs[2])(void *, const void *, size_t ), int printAll)
{
	t_memmove_tst tests[] = 
	{ 	
		memmove_createTestParams_Alloc("-----", "hello", 12,"Default behaviour"),
		memmove_createTestParams_Alloc("-----", "hello", 9,"1 Size smaller total of strings"),
		memmove_createTestParams_Alloc("-----", "hello", 7,"2 Size smaller total of strings"),
		memmove_createTestParams_Alloc("-----", "hello", 3, "Size smaller than dest"),
		memmove_createTestParams_SameStr ("Hello",0,1, 6, "1 Src and dest are in the same string"),
		memmove_createTestParams_SameStr ("Hello",1,0, 6, "2 Src and dest are in the same string"),
		memmove_createTestParams_SameStr ("Hello",0,1, 3, "3 Src and dest are in the same string"),
		memmove_createTestParams_SameStr ("Hello",1,0, 3, "4 Src and dest are in the same string"),

		memmove_createTestParams_Alloc("","",0,NULL)
	};
	
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_memove_result current = memmove_comparefunctions(tests[i],funcs);
		if(ret == 1 && !current.outResult)
			ret = 0;
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printResult(tests[i],current,printAll);
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
