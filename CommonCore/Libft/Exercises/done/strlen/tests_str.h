#include <stdio.h>
#include <string.h>
#include "libft.h"


typedef struct strlen_test
{
	char *str;
	char *name;
} t_strlen_tst;

t_strlen_tst createTestParam(char *str, char *name)
{
	t_strlen_tst retval;

	retval.str = str;
	retval.name = name;
	return retval;
}

int strlen_comparefunctions(t_strlen_tst test,size_t (*basefunc)(const char *),size_t (*myFunc)(const char *), int printAll )
{
	int mySize = myFunc(test.str);
	int baseSize = basefunc(test.str);

	if(printAll || mySize != baseSize )
	{
		printf(	"		MySize		(%d)\n", mySize);
		printf(	"		BaseSize	(%d)\n", baseSize);
	}
	return (mySize == baseSize);
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
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!strlen_comparefunctions(tests[i],basefunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}


