#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct rchr_tests
{
	void * ptr;
	int c;
	size_t size;
	char *name;

} t_rchr_tst;


t_rchr_tst rchr_createTestParams(void *ptr, int c, size_t size,char *name)
{
	t_rchr_tst retval;	
	retval.name = name;
	retval.c = c;
	retval.ptr = ptr;
	retval.size = size;
	return retval;
}


int rchr_comparefunctions(t_rchr_tst test, void *(*baseFunc)(void *, int, size_t), void *(*myFunc)(void *, int, size_t), int printAll)
{
	int retVal = 1;
	void *baseRet = baseFunc(test.ptr,test.c,test.size);
	void *myRet = myFunc(test.ptr,test.c,test.size);

	if(myRet != baseRet || printAll)
	{
		if(myRet != baseRet)
		{
			retVal = 0;
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");

		printf("		Base	%c\n", baseRet);
		printf("		Mine	%c\n", myRet);
	}

	return (retVal);
}

void rchr_logMessages(void *(*baseFunc)(void *, int, size_t), void *(*myFunc)(void *, int, size_t), int printAll)
{
	t_rchr_tst tests[] = 
	{ 	
		rchr_createTestParams('w', "Lowercase"),
		rchr_createTestParams('w', "Uppercase"),
		rchr_createTestParams('-', "Symbol"),
		rchr_createTestParams('\0', "Non printable"),
		rchr_createTestParams(300, "1 Invalid char value"),
		rchr_createTestParams(-300, "2 Invalid char value"),


		rchr_createTestParams('w', NULL),
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!rchr_comparefunctions(tests[i],baseFunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}
