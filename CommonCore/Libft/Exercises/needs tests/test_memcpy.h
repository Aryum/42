
#include	<string.h>
#include	<stdio.h>
#include 	<stdlib.h>

typedef struct memcpy_tests
{
	char* dst_new;
	char* dst_og;
	char* src;
	size_t size;
	char *name;

} t_memcpy_tst;


t_memcpy_tst memcpy_createTestParams_Alloc(char* dst,char* src, size_t size, char *name)
{
	t_memcpy_tst retval;	
	retval.name = name;
	retval.src = src;
	retval.dst_new = createstr(dst);
	retval.dst_og = createstr(dst);
	retval.size = size;
	
	return retval;
}
t_memcpy_tst memcpy_createTestParams_Default(char* dst,char* src, size_t size, char *name)
{
	t_memcpy_tst retval;	
	retval.name = name;
	retval.src = src;
	retval.dst_new = dst;
	retval.dst_og = src;

	retval.size = size;
	
	return retval;
}

void freeAlloc(t_memcpy_tst tst)
{
	free(tst.dst_new);
	free(tst.dst_og);
}
typedef struct strcmp_ret
{
	int success;
	unsigned int index;

} t_strcmp_ret;

t_strcmp_ret strComp(char *a,char *b)
{
	t_strcmp_ret retVal;
	int i = 0;
	while ((a[i] != '\0' || b[i] != '\0')) 
	{
		if(a[i] != b[i])
		{
			retVal.index = i;
			retVal.success = 0;
			return retVal;
		}
		i++;
	}		
	retVal.success = 1;
	retVal.index = 0;
	return retVal;
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

int memcpy_comparefunctions(t_memcpy_tst test, void(*baseFunc)(void *, const void *, size_t), void(*myFunc)(void *, const void *, size_t), int printAll)
{
	int retVal = 1;
	t_memcpy_tst basetest = memcpy_createTestParams_Alloc(test.dst_new, test.src, test.size,test.name);
	t_memcpy_tst mytest = memcpy_createTestParams_Alloc(test.dst_new, test.src, test.size,test.name);

	baseFunc(basetest.dst_new, basetest.src, basetest.size);
	myFunc(mytest.dst_new, mytest.src, mytest.size);

	t_strcmp_ret result = strComp(mytest.dst_new,basetest.dst_new);
	if(!result.success || printAll)
	{
		if(!result.success)
		{
			retVal = 0;
			printf("	Failed at index (%d)\n", result.index);
		}
		else
			printf("	Passed\n");

		printf("		Source	%s\n", test.src);
		printf("		Dst Og	%s\n", test.dst_og);
		printf("			Base	%s\n");
		printf("				%s\n", basetest.dst_new);
		printf("			Mine	%s\n");
		printf("				%s\n", mytest.dst_new);
		
	}
	freeAlloc(basetest);
	freeAlloc(mytest);

	return (retVal);
}

void memcpy_logMessages(void(*baseFunc)(void *, const void *, size_t), void(*myFunc)(void *, const void *, size_t), int printAll)
{
	//create a test that src and dest are part of the same string
	char *str1 = createstr("Hello");
	char *str2 = createstr("Hello");
	char *str3 = createstr("Hello");
	char *str4 = createstr("Hello");

	t_memcpy_tst tests[] = 
	{ 	
		memcpy_createTestParams_Alloc("-----", "hello",6,"Default behaviour"),
		memcpy_createTestParams_Alloc("-----", "hello",5,"Size smaller than strings"),
		memcpy_createTestParams_Alloc("---", "hello", 6,"Dst size Size smaller than both"),
		memcpy_createTestParams_Alloc("---", "hello", 5,"Dst size and Size smaller src"),
		memcpy_createTestParams_Alloc("-----", "hel", 6,"Src size smaller than both"),
		memcpy_createTestParams_Alloc("-----", "hel", 5,"Src size and Size smaller than dst"),
		memcpy_createTestParams_Alloc("-----", (void *)0, 1,"Src is null"),
		memcpy_createTestParams_Alloc( (void *)0,"hello", 6,"Dst is null"),
		memcpy_createTestParams_Alloc( (void *)0, (void *)0, 6,"Dst is null"),
		memcpy_createTestParams_Default (str1[0],str1[1], 6, "1 Src and dest are in the same string"),
		memcpy_createTestParams_Default (str2[1],str2[0], 6, "2 Src and dest are in the same string"),
		memcpy_createTestParams_Default (str3[0],str3[1], 3, "3 Src and dest are in the same string"),
		memcpy_createTestParams_Default (str4[1],str4[0], 3, "4 Src and dest are in the same string"),


		memcpy_createTestParams_Alloc("","","",NULL)
	};
	int i = 0;
	while (tests[i].name != NULL)
	{
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		if (!memcpy_comparefunctions(tests[i],baseFunc, myFunc, printAll))
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		freeAlloc(tests[i]);
		i++;
	}
}
