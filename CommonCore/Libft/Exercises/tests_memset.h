#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct memset_tests
{
	char *str;
	char *name;
	size_t size;
	char  c;

} t_memset_tst;

t_memset_tst mem_createTestParams(void * ptr, char c,size_t size, char *name)
{
	t_memset_tst retval;	
	retval.name = name;
	retval.str = ptr;
	retval.size = size;
	retval.c = c;
	return retval;
}


char *createstr(char *c)
{
	int size = strlen(c);
	char *alloc = malloc(size + 1);
	int i = 0;
	
	while(c[i] != '\0')
	{
		alloc[i] = c[i];
		i++;
	}
	alloc[i] = '\0';
	return alloc; 
}
int mem_comparefunctions(t_memset_tst test, void * (*baseFunc)(void *, int, size_t), void *  (*myFunc)(void *, int, size_t), int printAll)
{
	int retVal = 1;
	char *baseStr = baseFunc(createstr(test.str),test.c,test.size);
	char *myStr = myFunc(createstr(test.str),test.c,test.size);

	int isWorking = strcmp(baseStr, myStr); 
	if(!isWorking || printAll)
	{
		if(!isWorking)
		{
			retVal = 0;
			printf("	Failed\n");
		}
		else
			printf("	Passed\n");

		printf("		Base %s\n", baseStr);
		printf("		Mine %s\n", myStr);
	}
	free(baseStr);
	free(myStr);

	return (retVal);
}

void mem_logMessages(void * (*baseFunc)(void *, int, size_t), void *  (*myFunc)(void *, int, size_t), int printAll)
{
	t_memset_tst tests[] = 
	{ 	
		mem_createTestParams("123456", 'a', 6, "Normal behaviour"),
		mem_createTestParams("Teste", 'b', 3, "Smaller than total array"),
		mem_createTestParams("w", 'a', 1, ((void *)0)),
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!mem_comparefunctions(tests[i],baseFunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
}