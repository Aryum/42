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

typedef struct itoa_result
{
	char *myOut;
	t_strcmp_ret cmp;
	int outResult;
} t_itoa_result;

static t_itoa_tst itoa_createtest(int nbr,char *out, char* name)
{
	t_itoa_tst retval;
	retval.nbr = nbr; 
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

static t_itoa_result itoa_comparefunctions(t_itoa_tst test,FUNC)
{
	t_itoa_result retVal;
	retVal.myOut = func(test.nbr);
	retVal.cmp = strComp(retVal.myOut, test.out);
	retVal.outResult = retVal.cmp.sucess;
	return (retVal);
}
static void printresult(t_itoa_tst test,t_itoa_result res,int printAll)
{
	if(!res.outResult || printAll)
	{
		if(!res.outResult)
			printf("	Failed at index %d\n", res.cmp.index);
		else
			printf("	Passed\n");
		printf("		Return %s\n", nullcheck(res.myOut));
		printf("		Expected %s\n", nullcheck(test.out));

	}
	free(res.myOut);
}
void itoa_logMessages(FUNC, int printAll)
{
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
		t_itoa_result current = itoa_comparefunctions(tests[i],func); 
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printresult(tests[i],current, printAll);
			if (!current.outResult)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
		}
		i++;
	}
}
