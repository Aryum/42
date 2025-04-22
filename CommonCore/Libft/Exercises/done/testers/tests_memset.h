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

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

typedef struct mem_result
{
	char *baseStr;
	char *myStr;
	t_strcmp_ret cmp;
	int outResult;
}	t_mem_result;

static t_memset_tst mem_createTestParams(void * ptr, char c,size_t size, char *name)
{
	t_memset_tst retval;	
	retval.name = name;
	retval.str = ptr;
	retval.size = size;
	retval.c = c;
	return retval;
}

static t_strcmp_ret strComp(char *a,char *b)
{
	t_strcmp_ret retVal;
	int i = 0;
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
	retVal.sucess = 1;
	retVal.index = 0;
	return retVal;
}

static char *createstr(char *c)
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

static t_mem_result mem_comparefunctions(t_memset_tst test, void * (*baseFunc)(void *, int, size_t), void *  (*myFunc)(void *, int, size_t))
{
	t_mem_result retVal;
	retVal.baseStr = baseFunc(createstr(test.str),test.c,test.size);
	retVal.myStr = myFunc(createstr(test.str),test.c,test.size);
	retVal.cmp = strComp(retVal.baseStr, retVal.myStr); 
	retVal.outResult = retVal.cmp.sucess; 

	return (retVal);
}

static void printresult(t_memset_tst test,t_mem_result res, int printAll)
{
	if(!res.outResult || printAll)
	{
		if(!res.outResult)
			printf("	Failed at index (%d)\n", res.cmp.index);
		else
			printf("	Passed\n");

		printf("		Og		%s\n", test.str);
		printf("		Base	%s\n", res.baseStr);
		printf("		Mine	%s\n", res.myStr);
	}
	free(res.baseStr);
	free(res.myStr);
}

int mem_logMessages(void * (*baseFunc)(void *, int, size_t), void *  (*myFunc)(void *, int, size_t), int printAll)
{
	t_memset_tst tests[] = 
	{ 	
		mem_createTestParams("123456", 'a', 6, "Normal behaviour"),
		mem_createTestParams("Teste", 'b', 3, "Smaller than total array"),

		mem_createTestParams("w", 'a', 1, ((void *)0)),
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_mem_result current = mem_comparefunctions(tests[i],baseFunc, myFunc); 
		if(ret == 1 && !current.outResult)
			ret = 0;
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printresult(tests[i],current, printAll);
			if (!current.outResult)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
		}
		
		i++;
	}
	return ret;
}