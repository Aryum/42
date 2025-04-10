#include <stdio.h>
typedef struct tests
{
	char *name;
	int lower;
	int upper;
} t_tests;

t_tests createTestParams(int lower, int upper, char *name)
{
	t_tests retval;	
	retval.name = name;
	retval.lower = lower;
	retval.upper = upper;
	
	if(upper < lower)
	{
		printf("ERROR -> %s\nLower bound is bigger than upper (%d > %d)",name,lower, upper);		
	}
	return retval;
}

int comparefunctions(t_tests test, int (*baseFunc)(int), int (*myFunc)(int))
{
	int i = test.lower;
	while ( i <= test.upper)
	{
		if(baseFunc(i) != myFunc(i))
		{
			printf("	%c failed\n", i);
			printf("		Base result %s \n", (baseFunc(i) ? "True" : "False"));
			printf("		My result %s \n", (myFunc(i) ? "True" : "False"));


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
		if (!comparefunctions(tests[i],basefunc, myFunc))
			printf(	"			ERROR\n\n");
		else
			printf(	"			GOOD\n\n");
		i++;
	}
}