#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC char	*(*func)(char const *s, char (*f)(unsigned int, char))

typedef struct strmapi_tests
{

	char const *s; 
	char (*f)(unsigned int, char);
	char *out;
	char * name;

} t_strmapi_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

t_strmapi_tst strmapi_createtest(char const *s, char (*f)(unsigned int, char), char *out,char * name)
{
	t_strmapi_tst retval;
	retval.s = s;
	retval.f = f; 
	retval.out = out;
	retval.name = name;

	return retval;
}


t_strcmp_ret strComp(char *a,char *b)
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

char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}


int strmapi_comparefunctions(t_strmapi_tst test,FUNC , int printAll)
{
	int retVal = 1;
	char *myOut = func(test.s,test.f);
	t_strcmp_ret cmpRet;
	cmpRet = strComp(myOut, test.out);
	if(! cmpRet.sucess|| printAll)
	{
		if(!cmpRet.sucess)
		{
			retVal = 0;
			printf("	Failed at index %d\n", cmpRet.index);
		}
		else
			printf("	Passed\n");
		printf("		Return %s\n", nullcheck(myOut));
		printf("		Expected %s\n", nullcheck(test.out));

	}
	free(myOut);
	return (retVal);
}
char tst1(unsigned int i,char c)
{
	return c + 1;
}

char tst2(unsigned int i,char c)
{
	return c - 1;
}
char tst3(unsigned int i,char c)
{
	return '-';
}
void strmapi_logMessages(FUNC, int printAll)
{
	t_strmapi_tst tests[] = 
	{ 	
		strmapi_createtest("1234",tst1,"2345", "Test 1"),
		strmapi_createtest("1234",tst2,"0123", "Test 2"),
		strmapi_createtest("1234",tst3,"----", "Test 3"),
		strmapi_createtest(NULL,tst3,NULL, "Null"),
		strmapi_createtest("",tst1,NULL,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!strmapi_comparefunctions(tests[i],func, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
