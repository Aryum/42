#include <stdio.h>
#include <string.h>
#include "libft.h"

typedef struct strlen_test
{
	char *str;
	char *name;
} t_strlen_tst;

typedef struct strlen_result
{
	int mySize;
	int baseSize;
	int outResult;
} t_strlen_result;

static t_strlen_tst createTestParam(char *str, char *name)
{
	t_strlen_tst retval;

	retval.str = str;
	retval.name = name;
	return retval;
}

static t_strlen_result strlen_comparefunctions(t_strlen_tst test,size_t (*basefunc)(const char *),size_t (*myFunc)(const char *))
{
	t_strlen_result retVal;
	retVal.mySize = myFunc(test.str);
	retVal.baseSize = basefunc(test.str);
	retVal.outResult = retVal.mySize == retVal.baseSize; 
	return (retVal);
}

static void printresult(t_strlen_result res, int printAll)
{
	if(printAll || res.outResult)
	{
		printf(	"		MySize		(%d)\n", res.mySize);
		printf(	"		BaseSize	(%d)\n", res.baseSize);
	}
}

void  strlen_logMessages(size_t (*basefunc)(const char *),size_t (*myFunc)(const char *), int printAll)
{
	t_strlen_tst tests[] = 
	{ 	
		createTestParam("Teste", "Normal string"),
		createTestParam("", "Empty string"),
		createTestParam("", ((void *)0))
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		t_strlen_result current = strlen_comparefunctions(tests[i],basefunc, myFunc); 
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		printresult(current,printAll);
		if (!current.outResult)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}


