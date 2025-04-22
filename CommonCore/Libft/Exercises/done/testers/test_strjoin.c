#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC char	*(*func)(char const *, char const *)

typedef struct strjoin_tests
{
	char const *s1;
	char const *s2; 
	char * name;
	char *out;
} t_strjoin_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

typedef struct strjoin_result
{
	char *myOut;
	t_strcmp_ret cmpRet;
	int outResult;
} t_strjoin_result;

static t_strjoin_tst subsstr_createtest(char const *s1,char const *s2, char *out, char* name)
{
	t_strjoin_tst retval;
	retval.s1 = s1;
	retval.s2 = s2;
	retval.out = out;
	retval.name = name;

	return retval;
}

static t_strcmp_ret strComp(char *a,char *b)
{
	t_strcmp_ret retVal;
	int i = 0;
	if (a == NULL || b == NULL)
	{
		retVal.sucess = a == b;
		retVal.index = 0;
	}
	else
	{
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
	
		retVal.sucess = (a[i] == b[i]);
		retVal.index = retVal.sucess ? 0 : i;
	}
	return retVal;

}

static char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}

static t_strjoin_result strjoin_comparefunctions(t_strjoin_tst test,FUNC )
{
	t_strjoin_result retVal;
	retVal.myOut = func(test.s1, test.s2);
	retVal.cmpRet = strComp(retVal.myOut, test.out);
	retVal.outResult = retVal.cmpRet.sucess;

	return (retVal);
}

static void printresult(t_strjoin_tst test,t_strjoin_result res, int printAll)
{
	if(! res.cmpRet.sucess|| printAll)
	{
		if(!res.cmpRet.sucess)
			printf("	Failed at index %d\n", res.cmpRet.index);
		else
			printf("	Passed\n");

		printf("		Return %s\n", nullcheck(res.myOut));
	}
	free(res.myOut);
}

int strjoin_logMessages(FUNC, int printAll)
{
	t_strjoin_tst tests[] = 
	{ 	
		subsstr_createtest("A","B","AB", "Test 1"),
		subsstr_createtest("I am working"," or am i","I am working or am i", "Test 2"),
		subsstr_createtest(NULL," or am i",NULL, "1st string is null"),
		subsstr_createtest("I am working", NULL,NULL, "2nd string is null"),

		subsstr_createtest(NULL,NULL,NULL,NULL)
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_strjoin_result current = strjoin_comparefunctions(tests[i],func); 
		if(ret == 1 && !current.outResult)
			ret = 0;
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf("	Expected %s\n", nullcheck((char *)tests[i].out));
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
