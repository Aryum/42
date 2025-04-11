#include <stdio.h>
#include "libft.h"

typedef struct char_tests
{
	char *name;
	int lower;
	int upper;
} t_char_tst;

t_char_tst createTestParams(int lower, int upper, char *name)
{
	t_char_tst retval;	
	retval.name = name;
	retval.lower = lower;
	retval.upper = upper;
	if(upper < lower)
	{
		printf("ERROR -> %s\nLower bound is bigger than upper (%d > %d)",name,lower, upper);		
	}
	return retval;
}

int char_comparefunctions(t_char_tst test, int (*baseFunc)(int), int (*myFunc)(int), int printAll)
{
	int i = test.lower;
	int retVal = 1; 
	while ( i <= test.upper)
	{
		int myResult = myFunc(i);
		int baseResult = baseFunc(i);
		if (printAll || myResult != baseResult)
		{
			if(myResult != baseResult)
			{
				retVal = 0;
				printf("	%d(%c) Failed\n", i,i);
			}
			else
				printf("	%d(%c) Passed\n", i,i);
			printf("			Base result	%d \n", baseResult);
			printf("			My result	%d \n", myResult);
		}
		i++;
	}
	return retVal;
}

void  char_logMessages(int (*basefunc)(int),int (*myFunc)(int), int printAll)
{
	t_char_tst tests[] = 
	{ 	
		createTestParams(0, 32, "Special chars"), 
		createTestParams('!', '/', "Symbols pt1"), 
		createTestParams('0', '9', "Numbers"), 
		createTestParams(':', '@', "Symbols pt2"), 
		createTestParams('A', 'Z', "Upper case"), 
		createTestParams('[', '`', "Symbols pt3"), 
		createTestParams('a', 'z', "Lower case"), 
		createTestParams('{', 127, "Symbols pt4"), 
		createTestParams(-128, 0, "Negative chars"),
		createTestParams(255, 300, "Out of range value"),
		createTestParams(0, 0, ((void *) 0)),

	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!char_comparefunctions(tests[i],basefunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}


