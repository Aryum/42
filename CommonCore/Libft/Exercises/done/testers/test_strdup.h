#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct strdup_tests
{
	char *str;
	char *name;

} t_strdup_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

typedef struct strdup_result
{
	char *baseRet;
	char *myRet;
	t_strcmp_ret cmp;
	int outResult;
} t_strdup_result;

static t_strdup_tst strdup_createTestParams(char *str,char *name)
{
	t_strdup_tst retval;	
	retval.name = name;
	retval.str = str;

	return retval;
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
	
	retVal.sucess = a[i] == b[i];
	retVal.index = retVal.sucess ? 0 : i;
	return retVal;
}

static char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}

static void freeAlloc(t_strdup_tst test)
{
	free(test.str);
}

static t_strdup_result strdup_comparefunctions(t_strdup_tst test, char *(*func[2])(const char *))
{
	t_strdup_result retVal;
	retVal.baseRet = func[0](test.str);
	retVal.myRet = func[1](test.str);

	retVal.cmp = strComp(retVal.baseRet,retVal.myRet);
	retVal.outResult = retVal.cmp.sucess;
	return (retVal);
}

static void printresult(t_strdup_tst test,t_strdup_result res, int printAll)
{
	if(!res.cmp.sucess || printAll)
	{
		if(!res.cmp.sucess)
			printf("	Failed\n");
		else
			printf("	Passed\n");
		printf("	Og str %s\n", nullcheck(test.str));
		printf("	Og ptr %p\n", test.str);
		printf("			Base\n");
		printf("				string %s\n", nullcheck(res.baseRet) );
		printf("				new ptr %p\n", res.baseRet);
		
		printf("			Mine\n");
		printf("				string %s\n", nullcheck(res.myRet) );
		printf("				new ptr %p\n", res.myRet);
	}
	free(res.baseRet);
	free(res.myRet);
}

int strdup_logMessages(char *(*func[2])(const char *), int printAll)
{
	t_strdup_tst tests[] = 
	{ 	
		strdup_createTestParams("Hello I am working", "Default Behaviour"),
		strdup_createTestParams("", "Empty str"),

		strdup_createTestParams(0,NULL)
	};
	
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_strdup_result current = strdup_comparefunctions(tests[i],func);
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
		}
		i++;
	}
	return ret;
}
