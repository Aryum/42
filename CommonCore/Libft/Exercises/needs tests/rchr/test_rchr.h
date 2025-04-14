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


int rchr_comparefunctions(t_rchr_tst test, void *(*baseFunc)(const void *, int, size_t), void *(*myFunc)(const void *, int, size_t), int printAll)
{
	int retVal = 1;
	char *baseRet = (char *)baseFunc(test.ptr,test.c,test.size);
	char *myRet = (char *)myFunc(test.ptr,test.c,test.size);

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
		printf("			char	%c\n", baseRet != NULL ? *baseRet : '\0');
		printf("			ptr		%p\n", baseRet );
		printf("		Mine\n");
		printf("			char	%c\n", myRet != NULL ? *myRet : '\0');
		printf("			ptr		%p\n", myRet);
	}

	return (retVal);
}

void rchr_logMessages(void *(*baseFunc)(const void *, int, size_t), void *(*myFunc)(const void *, int, size_t), int printAll)
{
	t_rchr_tst tests[] = 
	{ 	
		rchr_createTestParams((void *)"tester",'e', 7, "Has char"),
		rchr_createTestParams((void *)"tester",'w', 7, "Doesnt have char"),
		rchr_createTestParams((void *)"tester",'r', 2, "Doesnt have char cos of size "),
		rchr_createTestParams((void *)"tester",'r', 10, "Has char and size bigger"),
		rchr_createTestParams((void *)"tester",'w', 10, "Doesnt have char and size bigger"),
		rchr_createTestParams((void *)0, 0, 0,NULL)
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
