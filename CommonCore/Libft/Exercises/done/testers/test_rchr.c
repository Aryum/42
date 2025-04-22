#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

#define FUNC void *(*func[2])(const void *, int, size_t)
typedef struct rchr_tests
{
	void * ptr;
	int c;
	size_t size;
	char *name;

} t_rchr_tst;

static t_rchr_tst rchr_createTestParams(void *ptr, int c, size_t size,char *name)
{
	t_rchr_tst retval;	
	retval.name = name;
	retval.c = c;
	retval.ptr = ptr;
	retval.size = size;
	return retval;
}

typedef struct rchr_result
{
	char *baseRet;
	char *myRet;
	int	outResult;
}	t_rchr_result;

static t_rchr_result rchr_comparefunctions(t_rchr_tst test, FUNC)
{
	t_rchr_result retVal;
	retVal.baseRet = (char *)func[0](test.ptr,test.c,test.size);
	retVal.myRet = (char *)func[1](test.ptr,test.c,test.size);
	retVal.outResult = retVal.myRet == retVal.baseRet; 
	

	return (retVal);
}

static void printresult(t_rchr_result res, int printAll)
{
	if(!res.outResult || printAll)
	{
		if(!res.outResult)
		{
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");

		printf("		Base\n");
		printf("			char	%c\n", res.baseRet != NULL ? res.baseRet[0] : '\0');
		printf("			ptr		%p\n", res.baseRet );
		printf("		Mine\n");
		printf("			char	%c\n", res.myRet != NULL ? res.myRet[0] : '\0');
		printf("			ptr		%p\n", res.myRet);
	}
}

int rchr_logMessages(FUNC, int printAll)
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
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_rchr_result current = rchr_comparefunctions(tests[i],func);
		if(ret == 1 && !current.outResult)
			ret = 0;
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printresult(current,printAll);
			if (!current.outResult)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
		}
		i++;
	}
	return ret;
}
