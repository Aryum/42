#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC char	*(*func)(char const *, char const *)

typedef struct strtrim_tests
{
	char const *s1;
	char const *set;
	char * name;
	char *out;
} t_strtrim_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

t_strtrim_tst subsstr_createtest(char const *s1,char const *set, char *out, char* name)
{
	t_strtrim_tst retval;
	retval.s1 = s1;
	retval.set = set;

	retval.out = out;
	retval.name = name;

	return retval;
}


t_strcmp_ret strComp(char *a,char *b)
{
	t_strcmp_ret retVal;
	int i = 0;
	if (a == NULL || b == NULL)
	{
		retVal.sucess = a == b;
		retVal.index = 0;
	}
	else
	{
		while ((a[i] != '\0' || b[i] != '\0')) 
		{
			if(a[i] != b[i])
			{
				retVal.index = i;
				retVal.sucess = 0;
				return retVal;
			}
			i++;
		}	
	
		retVal.sucess = (a[i] == b[i]);
		retVal.index = retVal.sucess ? 0 : i;
	}
	return retVal;

}

char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}


int strtrim_comparefunctions(t_strtrim_tst test,FUNC , int printAll)
{
	int retVal = 1;
	char *myOut = func(test.s1, test.set);
	t_strcmp_ret cmpRet;
	cmpRet = strComp(myOut, test.out);
	if(! cmpRet.sucess|| printAll)
	{
		if(!cmpRet.sucess)
		{
			retVal = 0;
			printf("	Failed at index %d\n", cmpRet.index);
		}
		else
			printf("	Passed\n");
		printf("		Base %s\n", nullcheck((char *)test.s1));
		printf("		Return %s\n", nullcheck(myOut));
		printf("		Expected %s\n", nullcheck(test.out));

	}
	free(myOut);
	return (retVal);
}

void strtrim_logMessages(FUNC, int printAll)
{
	//str vazia return vazio
	//char set \0 return str normal
	t_strtrim_tst tests[] = 
	{ 	
		subsstr_createtest("----ABAB----","-","ABAB", "Test 1"),
		subsstr_createtest("--++-ABAB--++---","-+","ABAB", "Test 2"),
		subsstr_createtest("ABAB-1234","-1234","ABAB", "Test 4"),
		subsstr_createtest("ABAB--++---","-+7094","ABAB", "Test 3"),
		subsstr_createtest("--++---ABAB","+-","ABAB", "Test 4"),
		subsstr_createtest("ABAB--++---","\0","ABAB--++---", "Charset is the null char"),
		subsstr_createtest(NULL," or am i",NULL, "String is null"),
		subsstr_createtest("I am working", NULL,"I am working", "Set is null"),

		subsstr_createtest(NULL,NULL,NULL,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!strtrim_comparefunctions(tests[i],func, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
