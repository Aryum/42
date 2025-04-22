#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC char **(*func)(char const *s, char c)

typedef struct split_tests
{
	char const *str;
	char c;
	char **out;
	char *name;
	int end;
} t_split_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

t_split_tst split_createtest(char const *str,char  c, char **out, char* name)
{
	t_split_tst retval;
	retval.str = str;
	retval.c = c;

	retval.out = out;
	retval.name = name;

	return retval;
}

t_split_tst split_createEnd()
{
	t_split_tst retval;
	retval.end = 1;
	retval.out = NULL;
	retval.str = NULL;

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
static void *freearr(char ***arr, int lastindex)
{
	while (lastindex >= 0)
	{
		if(arr[lastindex] != NULL)
			free((*arr)[lastindex]);
		lastindex--;
	}
	free(*arr);
	return (NULL);
}

int split_comparefunctions(t_split_tst test,FUNC , int printAll)
{
	char **myOut = func(test.str, test.c);

	t_strcmp_ret cmpRet;
	int i = 0;
	int retVal = 1;
	if(test.out != NULL)
	{
		while (myOut[i] != NULL && test.out[i] != NULL)
		{
			cmpRet = strComp(myOut[i], test.out[i]);
			if(! cmpRet.sucess|| printAll)
			{
				if(!cmpRet.sucess)
				{
					retVal = 0;
					printf("	Failed at index %d\n", i);
				}
				else
					printf("	Passed\n");
				printf("		Base	|%s|\n", nullcheck(test.out[i]));
				printf("		My		|%s|\n", nullcheck(myOut[i]));
			}
			i++;
		}
		freearr(&myOut,i);

	}
	else if(!test.end)
	{
		int result = test.out == NULL && myOut == NULL;
		if(!result || printAll)
		{
			if(!result)
			{
				retVal = 0;
				printf("	Failed \n");
			}
			else
				printf("	Passed\n");
			printf("		Base is null	%s\n",test.out == NULL ? "yes" : "no");
			printf("		My is null		%s\n", myOut == NULL ? "yes" : "no");
		}
	}
	return (retVal);
}

void split_logMessages(FUNC, int printAll)
{
	char *tst1[] = {"A","B","C","D","E","F", NULL};
	char *tst2[] = {"Aa","Bb","Cc","Dd","Ee","Ff", NULL};
	char *tst3[] = {"I am","+","working","idiot", NULL};
	char *tst4[] = {"I am-+-working-idiot", NULL};

	t_split_tst tests[] = 
	{ 	
		split_createtest("A B C D E F",' ',tst1, "Test 1"),
		split_createtest("Aa-Bb-Cc-Dd-Ee-Ff",'-',tst2, "Test 2"),
		split_createtest("I am-+-working-idiot",'-',tst3, "Test 2"),
		split_createtest("I am-+-working-idiot",'?',tst4, "Char not in the str"),
		split_createtest(NULL,'w',NULL, "str is null"),

		split_createtest(NULL,' ',NULL,NULL)
	};
	
	int i = 0;
	int ret = 1;
	int current = 1;
	while (tests[i].name != NULL)
	{
		current = split_comparefunctions(tests[i],func, printAll);
		if(ret == 1 && !current)
			ret = 0;
		if(!current || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			if (!current)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
			i++;
		} 
	}
	return ret;
}
