#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>


typedef struct atoi_tests
{
	char* str;
	char* name;
} t_atoi_tst;

t_atoi_tst atoi_createTestParams(char * str,char *name)
{
	t_atoi_tst retval;	
	retval.name = name;
	retval.str = str;
	return retval;
}

int atoi_comparefunctions(t_atoi_tst  test, int(*func[2])(const char *), int printAll)
{
	int retVal = 1;
	int baseRet = func[0](test.str);
	int myRet = func[1](test.str);

	if(myRet != baseRet || printAll)
	{
		if(myRet != baseRet)
		{
			retVal = 0;
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");

		printf("		Base	%d\n", baseRet);
		printf("		Mine	%d\n", myRet);
	}

	return (retVal);
}

void atoi_logMessages(int(*func[2])(const char *), int printAll)
{
	t_atoi_tst  tests[] = 
	{ 	
		atoi_createTestParams("12345", "Default behaviour"),
		atoi_createTestParams("  12345", "Spaces"),
		atoi_createTestParams("  +12345", "1 Spaces with simbol"),
		atoi_createTestParams("  -12345", "2 Spaces with simbol"),
		atoi_createTestParams("  -+12345", "3 Spaces with simbol"),
		atoi_createTestParams("  -+123  45", "4 Spaces with simbol"),
		atoi_createTestParams("-12345", "Negative number"),
		atoi_createTestParams("+12345", "Positive simbol"),
		atoi_createTestParams("a12345", "Has letter before nbr"),
		atoi_createTestParams("123a45", "Has letter int the middle"),
		atoi_createTestParams("--12345", "Multiple simbols 1"),
		atoi_createTestParams("-+-12345", "Multiple simbols 2"),
		atoi_createTestParams("2147483647", "Max int"),
		atoi_createTestParams("21474836481", "Overflow"),

		atoi_createTestParams("", NULL),
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!atoi_comparefunctions(tests[i],func, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
