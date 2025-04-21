
#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct tochr_tests
{
	int c;
	char *name;

} t_tochr_tst;


t_tochr_tst tochr_createTestParams(int c,char *name)
{
	t_tochr_tst retval;	
	retval.name = name;
	retval.c = c;
	
	return retval;
}


int tochr_comparefunctions(t_tochr_tst test, int(*baseFunc)(int), int(*myFunc)(int), int printAll)
{
	int retVal = 1;
	int baseRet = baseFunc(test.c);
	int myRet = myFunc(test.c);

	if(myRet != baseRet || printAll)
	{
		if(myRet != baseRet)
		{
			retVal = 0;
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");

		printf("		Base	%c\n", baseRet);
		printf("		Mine	%c\n", myRet);
	}

	return (retVal);
}

void tochr_logMessages(int(*baseFunc)(int), int(*myFunc)(int), int printAll)
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
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!tochr_comparefunctions(tests[i],baseFunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
