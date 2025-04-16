#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct strdup_tests
{
	char *str;
	char *name;

} t_strdup_tst;


t_strdup_tst strdup_createTestParams(char *str,char *name)
{
	t_strdup_tst retval;	
	retval.name = name;
	retval.str = str;
	retval.big = name;
	retval.size = size;


	return retval;
}


int strdup_comparefunctions(t_strdup_tst test, char *(*func[2])(const char *, const char *, size_t), int printAll)
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

	return (retVal);
}

void strdup_logMessages(char *(*func[2])(const char *, const char *, size_t), int printAll)
{
	t_strdup_tst tests[] = 
	{ 	
		strdup_createTestParams("Hello I am working", " ", 19, "1 Has substr"),
		strdup_createTestParams("Hello I am working", "am", 19, "2 Has substr"),
		strdup_createTestParams("Hello I am working","-", 19, "1 Doesnt have"),
		strdup_createTestParams("Hello I am working", "89", 19, "2 Doesnt have"),
		strdup_createTestParams("Hello I am working", "amd", 19, "Doesnt have full little"),
		strdup_createTestParams("Hello I am working", "am", 5, "Doesnt have because size"),
		strdup_createTestParams("Hello I am working", "Hel", 5, "Has but smaller size"),

		strdup_createTestParams(0, 0, 0,NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!strdup_comparefunctions(tests[i],func, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
