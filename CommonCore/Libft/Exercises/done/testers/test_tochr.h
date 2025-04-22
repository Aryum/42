
#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct tochr_tests
{
	int c;
	char *name;

} t_tochr_tst;

typedef struct tochr_result
{
	int baseRet;
	int myRet;
	int outResult;
}	t_tochr_result;

static t_tochr_tst tochr_createTestParams(int c,char *name)
{
	t_tochr_tst retval;	
	retval.name = name;
	retval.c = c;
	
	return retval;
}

static t_tochr_result tochr_comparefunctions(t_tochr_tst test, int(*baseFunc)(int), int(*myFunc)(int))
{
	t_tochr_result retVal;
	retVal.baseRet = baseFunc(test.c);
	retVal.myRet = myFunc(test.c);
	retVal.outResult = retVal.myRet == retVal.baseRet;

	return (retVal);
}

static void printresult(t_tochr_result res,int printAll)
{
	if(!res.outResult || printAll)
	{
		if(!res.outResult)
			printf("	Failed\n");
		else
			printf("	Passed\n");

		printf("		Base	%c\n", res.baseRet);
		printf("		Mine	%c\n", res.myRet);
	}
}

int tochr_logMessages(int(*baseFunc)(int), int(*myFunc)(int), int printAll)
{
	t_tochr_tst tests[] = 
	{ 	
		tochr_createTestParams('w', "Lowercase"),
		tochr_createTestParams('w', "Uppercase"),
		tochr_createTestParams('-', "Symbol"),
		tochr_createTestParams('\0', "Non printable"),
		tochr_createTestParams(300, "1 Invalid char value"),
		tochr_createTestParams(-300, "2 Invalid char value"),


		tochr_createTestParams('w', NULL),
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_tochr_result current = tochr_comparefunctions(tests[i],baseFunc, myFunc);
		if(ret == 1 && !current.outResult)
			ret = 0; 
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printresult(current,printAll);
			if (!current.outResult)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
		}
		i++;
	}
	return ret;
}
