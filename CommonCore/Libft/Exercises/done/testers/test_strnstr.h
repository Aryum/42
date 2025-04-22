#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct strnstr_tests
{
	char *little;
	char *big;
	size_t size;

	char *name;

} t_strnstr_tst;

char *createstr(char *c)
{
	int size = 0;
	while(c[size] != '\0')
		size++;
	int i = 0;
	char *alloc = (char *)malloc(size + 1);
	
	while(c[i] != '\0')
	{
		alloc[i] = c[i];
		i++;
	}
	alloc[i] = '\0';
	return alloc; 
}

t_strnstr_tst strnstr_createTestParams(char *little,char *big,  size_t size,char *name)
{
	t_strnstr_tst retval;	
	retval.name = name;
	retval.little = createstr(little);
	retval.big = createstr(big);
	retval.size = size;


	return retval;
}

void  freeAlloc(t_strnstr_tst tst)
{
	free(tst.big);
	free(tst.little);
}

typedef struct strnstr_result
{
	char *baseRet;
	char *myRet;
	int outresult;

} t_strnstr_result;

t_strnstr_result strnstr_comparefunctions(t_strnstr_tst test, char *(*func[2])(const char *, const char *, size_t))
{
	t_strnstr_result retVal;
	retVal.baseRet = func[0](test.big,test.little,test.size);
	retVal.myRet = func[1](test.big,test.little,test.size);
	retVal.outresult = retVal.myRet == retVal.baseRet;
	
	return (retVal);
}

void printresult(t_strnstr_tst test,t_strnstr_result res, int printAll)
{
	if(!res.outresult || printAll)
	{
		if(!res.outresult)
			printf("	Failed\n");
		else
			printf("	Passed\n");

		printf("		Base\n");
		printf("			str		%s\n", res.baseRet != NULL ? res.baseRet : "(Empty)");
		printf("			ptr		%p\n", res.baseRet );
		printf("		Mine\n");
		printf("			str		%s\n", res.myRet != NULL ? res.myRet : "(Empty)");
		printf("			ptr		%p\n", res.myRet);
	}
	freeAlloc(test);
}

void strnstr_logMessages(char *(*func[2])(const char *, const char *, size_t), int printAll)
{
	t_strnstr_tst tests[] = 
	{ 	
		strnstr_createTestParams("Hello I am working", " ", 19, "1 Has substr"),
		strnstr_createTestParams("Hello I am working", "am", 19, "2 Has substr"),
		strnstr_createTestParams("Hello I am working","-", 19, "1 Doesnt have"),
		strnstr_createTestParams("Hello I am working", "89", 19, "2 Doesnt have"),
		strnstr_createTestParams("Hello I am working", "amd", 19, "Doesnt have full little"),
		strnstr_createTestParams("Hello I am working", "am", 5, "Doesnt have because size"),
		strnstr_createTestParams("Hello I am working", "Hel", 5, "Has but smaller size"),
		strnstr_createTestParams("Hello I am working", NULL, 19, "Null pointer"),
		strnstr_createTestParams("Hello I am working", "", 19, "Empty string"),

		strnstr_createTestParams(0, 0, 0,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		t_strnstr_result current = strnstr_comparefunctions(tests[i],func); 
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		printresult(tests[i], current, printAll);
		if (!current.outresult)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
