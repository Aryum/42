#include <stdio.h>
typedef struct tests
{
	char *name;
	int lower;
	int upper;
	int expectedResult;
} t_tests;

t_tests createTestParams_BASE(int lower, int upper, char *name, int (*func)(int))
{
	t_tests retval;
	int i = lower;
	
	retval.name = name;
	retval.lower = lower;
	retval.upper = upper;
	
	if(upper < lower)
	{
		printf("ERROR -> %s\nLower bound is bigger than upper (%d > %d)",name,lower, upper);		
	}
	else
	{
		while ( i <= upper)
		{
			if(!func(i))
			{
				printf("%s is FALSE\n	[(%c)-(%c)]\n", name, lower,upper);
				retval.expectedResult = 0;
				return retval;				
			}
			i++;
		}	
		printf("%s is TRUE\n	[(%c)-(%c)]\n", name, lower,upper);

		retval.expectedResult = 1;
	}
	return retval;
}

int comparefunctions(t_tests test, int (*func)(int))
{
	int i = test.lower;
	while ( i <= test.upper)
	{
		if(func(i) != test.expectedResult)
		{
			printf("%c failed", i);
			return 0;				
		}
		i++;
	}
	return 1;
}

void  logMessages(int (*func)(int))
{
	t_tests tests[] = 
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
		createTestParams(0, 0, (void *)0),

	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		if (!comparefunctions(tests[i], func))
			printf(	"	ERROR\n");
		else
			printf(	"	GOOD\n\n");
		i++;
	}
}