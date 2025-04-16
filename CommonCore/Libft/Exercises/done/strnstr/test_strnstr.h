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
int strnstr_comparefunctions(t_strnstr_tst test, char *(*func[2])(const char *, const char *, size_t), int printAll)
{
	int retVal = 1;
	char *baseRet = func[0](test.big,test.little,test.size);
	char *myRet = func[1](test.big,test.little,test.size);

	if(myRet != baseRet || printAll)
	{
		if(myRet != baseRet)
		{
			retVal = 0;
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");

		printf("		Base\n");
		printf("			str		%s\n", baseRet != NULL ? baseRet : "(Empty)");
		printf("			ptr		%p\n", baseRet );
		printf("		Mine\n");
		printf("			str		%s\n", myRet != NULL ? myRet : "(Empty)");
		printf("			ptr		%p\n", myRet);
	}
	freeAlloc(test);
	return (retVal);
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

		strnstr_createTestParams(0, 0, 0,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!strnstr_comparefunctions(tests[i],func, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
