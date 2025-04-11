#include <stdio.h>
#include <string.h>
#include "libft.h"


typedef struct strlen_test
{
	char *str;
	char *name;
} t_strlen_tst;

t_strlen_tst creteTestParam(char *str, char *name)
{
	t_strlen_tst retval;

	retval.str = str;
	retval.name = name;

}

int strlen_comparefunctions(t_strlen_tst test,int (*basefunc)(char *),int (*myFunc)(char *), int printAll )
{
	return (basefunc(test.str) != myFunc(test.str));
}
void  strlen_logMessages(int (*basefunc)(char *),int (*myFunc)(char *), int printAll)
{
	t_strlen_tst tests[] = 
	{ 	
		creteTestParam("Teste", "Normal string"),
		creteTestParam("", "Empty string"),

	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		if (!strlen_comparefunctions(tests[i],basefunc, myFunc, printAll))
			printf(	"			ERROR\n\n");
		else
			printf(	"			GOOD\n\n");
		i++;
	}
}


