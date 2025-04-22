#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>

typedef struct cmp_tests
{
	void *str1;
	void *str2;
	size_t size;
	char *name;

} t_cmp_tst;

typedef struct cmp_result
{
	int baseRet;
	int myRet;
	int outResult;
}	t_cmp_result;

static t_cmp_tst cmp_createTestParams(void * ptr1, void * ptr2, size_t size,char *name)
{
	t_cmp_tst retval;	
	retval.name = name;
	retval.str1 = ptr1;
	retval.str2 = ptr2;
	retval.size = size;
	return retval;
}

static char *createstr(char *c)
{
	int size = strlen(c);
	char *alloc = (char *)malloc(size + 1);
	int i = 0;
	
	while(c[i] != '\0')
	{
		alloc[i] = c[i];
		i++;
	}
	alloc[i] = '\0';
	return alloc; 
}

static t_cmp_result cmp_comparefunctions(t_cmp_tst test, int(*baseFunc)(const void *, const void *, size_t), int(*myFunc)(const void *, const void *, size_t))
{
	t_cmp_result retVal;
	retVal.baseRet = baseFunc(test.str1, test.str2 ,test.size);
	retVal.myRet = myFunc(test.str1, test.str2 ,test.size);
	retVal.outResult = retVal.myRet == retVal.baseRet;
	return (retVal);
}

static void printresult(t_cmp_tst test,t_cmp_result res, int printAll)
{
	if(!res.outResult || printAll)
	{
		if(!res.outResult)
			printf("	Failed\n");
		else
			printf("	Passed\n");
		printf("	Comparing %ld bytes\n", test.size);
		printf("	Str1 %s\n", (char *)test.str1);
		printf("	Str2 %s\n", (char *)test.str2);

		printf("		Base	%d\n", res.baseRet);
		printf("		Mine	%d\n", res.myRet);
	}

}

static void *str_invalidchar(int value)
{
	int *str = malloc(2 *sizeof(int));
	str[0] = value;
	str[1] = '\0';
	return str;
}

int cmp_logMessages(int(*baseFunc)(const void *, const void *, size_t), int(*myFunc)(const void *, const void *, size_t), int printAll)
{
	void * invalidchar1 = str_invalidchar(-50);
	void * invalidchar1_cpy = str_invalidchar(-50);

	void * invalidchar2 = str_invalidchar(-300);
	t_cmp_tst tests[] = 
	{ 	
		cmp_createTestParams((void *)"123456",(void *)"123456" , 7, "Same str total size"),
		cmp_createTestParams((void *)"123456",(void *)"023456" , 7, "1 Dif str total size"),
		cmp_createTestParams((void *)"123456",(void *)"128456" , 7, "2 Dif str total size"),
		cmp_createTestParams((void *)"","1" , 1, "3 Dif str total size"),
		cmp_createTestParams((void *)"","1" , 0, "4 Dif str total size"),

		cmp_createTestParams((void *)"123456",(void *)"123456" , 5, "Same str smaller size"),
		cmp_createTestParams((void *)"aa1aa",(void *)"aaaaa" , 5, "1 Dif str smaller size"),
		cmp_createTestParams((void *)"aaaaaa1",(void *)"aaaaaaa" , 5, "2 Dif str smaller size"),
		cmp_createTestParams(invalidchar1,invalidchar1_cpy, 1, "Strs with same invalid char"),
		cmp_createTestParams(invalidchar1,invalidchar2, 1, "Strs with dif invalid char"),

		cmp_createTestParams((void *)0,(void *)0, 0, (void *)0),
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_cmp_result current = cmp_comparefunctions(tests[i],baseFunc, myFunc);
		if(ret == 1 && !current.outResult)
			ret = 0;
		if(!current.outResult || printAll)
		{
			printf("Testing %s\n", tests[i].name);
			printf(	"-----------------------------------------\n");
			printresult(tests[i],current,printAll);
			if (!current.outResult)
				printf(	"------------------ERROR------------------\n\n");
			else
				printf(	"------------------GOOD------------------\n\n");
		}
		i++;
	}
	free(invalidchar1);
	free(invalidchar2);
	return ret;
}
