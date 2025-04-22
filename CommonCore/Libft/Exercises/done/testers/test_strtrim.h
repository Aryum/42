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

typedef struct strtrim_result
{
	char *myOut;
	t_strcmp_ret cmpRet;
	int outResult;
} t_strtrim_result;

static t_strtrim_tst strtrim_createtest(char const *s1,char const *set, char *out, char* name)
{
	t_strtrim_tst retval;
	retval.s1 = s1;
	retval.set = set;

	retval.out = out;
	retval.name = name;

	return retval;
}

static t_strcmp_ret strComp(char *a,char *b)
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

static char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}

static t_strtrim_result strtrim_comparefunctions(t_strtrim_tst test,FUNC)
{
	t_strtrim_result retVal;
	retVal.myOut = func(test.s1, test.set);
	retVal.cmpRet = strComp(retVal.myOut, test.out);
	retVal.outResult = retVal.cmpRet.sucess; 
	return (retVal);
}

static void printresult(t_strtrim_tst test,t_strtrim_result res, int printAll)
{
	if(! res.outResult|| printAll)
	{
		if(!res.outResult)
			printf("	Failed at index %d\n", res.cmpRet.index);
		else
			printf("	Passed\n");
		printf("		Base %s\n", nullcheck((char *)test.s1));
		printf("		Return %s\n", nullcheck(res.myOut));
		printf("		Expected %s\n", nullcheck(test.out));

	}
	free(res.myOut);
}

void strtrim_logMessages(FUNC, int printAll)
{
	t_strtrim_tst tests[] = 
	{ 	
		strtrim_createtest("----ABAB----","-","ABAB", "Test 1"),
		strtrim_createtest("--++-ABAB--++---","-+","ABAB", "Test 2"),
		strtrim_createtest("ABAB-1234","-1234","ABAB", "Test 4"),
		strtrim_createtest("ABAB--++---","-+7094","ABAB", "Test 3"),
		strtrim_createtest("--++---ABAB","+-","ABAB", "Test 4"),
		strtrim_createtest("ABAB--++---","\0","ABAB--++---", "Charset is the null char"),

		strtrim_createtest("abababab|abababababab|abababaaaaaabbbb","ab","|abababababab|", "Charset is the null char"),


		strtrim_createtest(NULL," or am i",NULL, "String is null"),
		strtrim_createtest("I am working", NULL,"I am working", "Set is null"),

		strtrim_createtest(NULL,NULL,NULL,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		t_strtrim_result current = strtrim_comparefunctions(tests[i],func); 
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		printresult(tests[i],current, printAll);
		if (!current.outResult)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
