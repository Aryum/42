#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC char	*(*func)(int)

typedef struct itoa_tests
{
	int nbr;
	char *out;
	char * name;

} t_itoa_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

t_itoa_tst itoa_createtest(int nbr,char *out, char* name)
{
	t_itoa_tst retval;
	retval.nbr = nbr; 
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


int itoa_comparefunctions(t_itoa_tst test,FUNC , int printAll)
{
	int retVal = 1;
	char *myOut = func(test.nbr);
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

void itoa_logMessages(FUNC, int printAll)
{
	//str vazia return vazio
	//char set \0 return str normal
	t_itoa_tst tests[] = 
	{ 	
		itoa_createtest(1234,"1234", "Test 1"),
		itoa_createtest(-1234,"-1234", "Test 2"),
		itoa_createtest(0,"0", "Test 3"),
		itoa_createtest(-2147483648,"-2147483648", "Test 4"),
		itoa_createtest(2147483647,"2147483647", "Test 5"),
		itoa_createtest(0,NULL,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!itoa_comparefunctions(tests[i],func, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
