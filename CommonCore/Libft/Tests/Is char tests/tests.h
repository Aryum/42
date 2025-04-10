#include <stdio.h>
typedef struct tests
{
	char *name;
	int lower;
	int upper;
} t_tests;

t_tests createTestParams(int lower, int upper, char *name, int (*func)(int))
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
	return retval;
}

int comparefunctions(t_tests test,int (*baseFunc)(int), int (*myFunc)(int))
{
	int i = test.lower;
	while ( i <= test.upper)
	{
		if(baseFunc(i) != myFunc(i))
		{
			printf("%c failed", i);
			return 0;				
		}
		i++;
	}
	return 1;
}

void  logMessages(int (*basefunc)(int),int (*myFunc)(int))
{
	t_tests tests[] = 
	{ 	
		createTestParams(0, 32, "Special chars",basefunc), 
		createTestParams('!', '/', "Symbols pt1",basefunc), 
		createTestParams('0', '9', "Numbers",basefunc), 
		createTestParams(':', '@', "Symbols pt2",basefunc), 
		createTestParams('A', 'Z', "Upper case",basefunc), 
		createTestParams('[', '`', "Symbols pt3",basefunc), 
		createTestParams('a', 'z', "Lower case",basefunc), 
		createTestParams('{', 127, "Symbols pt4",basefunc), 
		createTestParams(-128, 0, "Negative chars",basefunc),
		createTestParams(255, 300, "Out of range value",basefunc),
		createTestParams(0, 0, (void *)0,basefunc),

	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		if (!comparefunctions(tests[i], myFunc))
			printf(	"	ERROR\n");
		else
			printf(	"	GOOD\n\n");
		i++;
	}
}