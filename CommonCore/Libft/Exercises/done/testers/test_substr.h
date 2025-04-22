#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC char	*(*func)(char const *, unsigned int, size_t)

typedef struct substr_tests
{
	char const *s; 
	unsigned int start; 
	size_t len;
	char * name;
	char *out;

} t_substr_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

typedef struct substr_result
{
	char *myOut;
	t_strcmp_ret cmpRet;
	int outResult;
} t_substr_result;

static t_substr_tst subsstr_createtest(char const *s, unsigned int start, size_t len, char *out, char* name)
{
	t_substr_tst retval;
	retval.s = s;
	retval.start = start;
	retval.len = len;
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

static t_substr_result substr_comparefunctions(t_substr_tst test,FUNC)
{
	t_substr_result retVal;
	retVal.myOut = func(test.s,test.start,test.len);
	retVal.cmpRet = strComp(retVal.myOut, test.out);
	retVal.outResult = retVal.cmpRet.sucess; 

	return (retVal);
}

static void printresult(t_substr_tst test,t_substr_result res, int printAll)
{
	if(! res.outResult || printAll)
	{
		if(!res.outResult)
			printf("	Failed at index %d\n", res.cmpRet.index);
		else
			printf("	Passed\n");

		printf("		Got	%s\n", nullcheck(res.myOut));
		if(res.myOut != NULL)
		{
			printf("		Starting at	(%d)->%c\n", test.start ,test.s[test.start]);
			printf("		Ending at	(%ld)->%c\n", test.start + test.len ,test.s[test.start + test.len - 1]);
			printf("		Out Pointer (%p)\n", res.myOut);
			printf("		Og Pointer	(%p)\n", test.s);
		}
	}
}

void substr_logMessages(FUNC, int printAll)
{
	t_substr_tst tests[] = 
	{ 	
		subsstr_createtest("Trim after 123456789",11,9,"123456789", "Take numbers out"),
		subsstr_createtest("1234",1,3,"234", "Trimmed start"),
		subsstr_createtest("1234",0,4,"1234", "Returns a dupped string"),
		subsstr_createtest("1234",5,0,"","Starts in index bigger than str"),

		subsstr_createtest("",0,0,NULL,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		t_substr_result current = substr_comparefunctions(tests[i],func); 
		printf("Testing %s\n", tests[i].name);
		printf("	Expected %s\n", nullcheck((char *)tests[i].out));
		printf(	"-----------------------------------------\n");
		printresult(tests[i], current, printAll);
		if (!current.outResult)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
