#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct strdup_tests
{
	char *str;
	char *name;

} t_strdup_tst;


t_strdup_tst strdup_createTestParams(char *str,char *name)
{
	t_strdup_tst retval;	
	retval.name = name;
	retval.str = str;

	return retval;
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
	
	retVal.sucess = a[i] == b[i];
	retVal.index = retVal.sucess ? 0 : i;
	return retVal;
}

char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}

void freeAlloc(t_strdup_tst test)
{
	free(test.str);
}
int strdup_comparefunctions(t_strdup_tst test, char *(*func[2])(const char *), int printAll)
{
	int retVal = 1;
	char *baseRet = func[0](test.str);
	char *myRet = func[1](test.str);

	t_strcmp_ret cmp = strComp(baseRet,myRet);
	if(!cmp.sucess|| printAll)
	{
		if(!cmp.sucess)
		{
			retVal = 0;
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");
		printf("	Og str %s\n", nullcheck(test.str));
		printf("	Og ptr %p\n", test.str);
		printf("			Base\n");
		printf("				string %s\n", nullcheck(baseRet) );
		printf("				new ptr %p\n", baseRet);
		
		printf("			Mine\n");
		printf("				string %s\n", nullcheck(myRet) );
		printf("				new ptr %p\n", myRet);
	}
	free(baseRet);
	free(myRet);
	return (retVal);
}

void strdup_logMessages(char *(*func[2])(const char *), int printAll)
{
	t_strdup_tst tests[] = 
	{ 	
		strdup_createTestParams("Hello I am working", "Default Behaviour"),
		strdup_createTestParams("", "Empty str"),



		strdup_createTestParams(0,NULL)
	};
	
	int i = 0;
	int ret = 1;
	int current = 1;
	while (tests[i].name != NULL)
	{
		current = strdup_comparefunctions(tests[i],func, printAll);
		if(ret == 1 && !current)
			ret = 0;
		if(!current || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			if (!current)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
			i++;
		} 
	}
	return ret;
}
