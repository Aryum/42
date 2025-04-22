#include <stdio.h>
#include <string.h>
#include "libft.h"

#define FUNC size_t (*func[2])(const char *)

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

static t_strlen_result strlen_comparefunctions(t_strlen_tst test, FUNC)
{
	t_strlen_result retVal;
	retVal.mySize = func[0](test.str);
	retVal.baseSize = func[1](test.str);
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

int  strlen_logMessages(FUNC, int printAll)
{
	t_strlen_tst tests[] = 
	{ 	
		createTestParam("Teste", "Normal string"),
		createTestParam("", "Empty string"),
		createTestParam("", ((void *)0))
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_strlen_result current = strlen_comparefunctions(tests[i],func); 
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


