#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC 
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

typedef struct atoi_result
{
	int myRet;
	int baseRet;
	int outResult;
}	t_atoi_result;

static t_atoi_result atoi_comparefunctions(t_atoi_tst  test, int(*func[2])(const char *))
{
	t_atoi_result retVal;
	retVal.baseRet = func[0](test.str);
	retVal.myRet = func[1](test.str);
	retVal.outResult = retVal.myRet == retVal.baseRet;

	return (retVal);
}

static void printresult(t_atoi_result result, int printAll)
{
	if(!(result.outResult) || printAll)
	{
		if(!result.outResult)
			printf("	Failed\n");
		else
			printf("	Passed\n");
		printf("		Base	%d\n", result.baseRet);
		printf("		Mine	%d\n", result.myRet);
	}
}

int atoi_logMessages(int(*func[2])(const char *), int printAll)
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
	int ret = 1;
	t_atoi_result current;
	while (tests[i].name != NULL)
	{
		current = atoi_comparefunctions(tests[i],func);
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
