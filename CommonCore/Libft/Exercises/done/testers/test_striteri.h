#include	<string.h>
#include	<stdio.h>
#include <stdlib.h>
#include "libft.h"
#define FUNC void(*func)(char *s, void (*f)(unsigned int, char*))

typedef struct striteri_tests
{

	char  *s; 
	void (*f)(unsigned int, char*);
	char *out;
	char * name;

} t_striteri_tst;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

char *createstr(char *c)
{
	if(c == NULL)
		return NULL;
	char *alloc = (char *)malloc(strlen(c) + 1);
	int i = 0;
	
	while(c[i] != '\0')
	{
		alloc[i] = c[i];
		i++;
	}
	alloc[i] = '\0';
	return alloc; 
}

t_striteri_tst striteri_createtest(char *s, void (*f)(unsigned int, char*), char *out,char * name)
{
	t_striteri_tst retval;
	if(name != NULL)
		retval.s = createstr(s);
	retval.f = f; 
	retval.out = out;
	retval.name = name;

	return retval;
}


t_strcmp_ret strComp(char *a,char *b)
{
	t_strcmp_ret retVal;
	int i = 0;
	if (a == NULL || b == NULL)
	{
		retVal.sucess = a == b;
		retVal.index = 0;
	}
	else
	{
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
	
		retVal.sucess = (a[i] == b[i]);
		retVal.index = retVal.sucess ? 0 : i;
	}
	return retVal;

}

char *nullcheck(char *str)
{
	if(str != NULL)
		return str;
	return "(string is null)";
}


t_strcmp_ret striteri_comparefunctions(t_striteri_tst test,FUNC)
{
	func(test.s,test.f);
	t_strcmp_ret cmpRet;
	cmpRet = strComp(test.s, test.out);
	
	return (cmpRet);
}

void printresult(t_striteri_tst test, t_strcmp_ret cmpRet, int printAll)
{
	if(! cmpRet.sucess|| printAll)
	{
		if(!cmpRet.sucess)
			printf("	Failed at index %d\n", cmpRet.index);
		else
			printf("	Passed\n");
		printf("		Return %s\n", nullcheck(test.s));
		printf("		Expected %s\n", nullcheck(test.out));

	}
	if(test.s != NULL)
		free(test.s);
}

void tst1(unsigned int i,char *c)
{
	(*c) += 1;
}

void tst2(unsigned int i,char *c)
{
	(*c) -= 1;
}
void tst3(unsigned int i,char *c)
{
	(*c) = '-';
}
int striteri_logMessages(FUNC, int printAll)
{
	t_striteri_tst tests[] = 
	{ 	
		striteri_createtest("1234",tst1,"2345", "Test 1"),
		striteri_createtest("1234",tst2,"0123", "Test 2"),
		striteri_createtest("1234",tst3,"----", "Test 3"),
		striteri_createtest(NULL,tst3,NULL, "Null"),
		striteri_createtest("",tst1,NULL,NULL)
	};
	int i = 0;
	int ret = 1;
	while (tests[i].name != NULL)
	{
		t_strcmp_ret current = striteri_comparefunctions(tests[i],func);
		if(ret == 1 && !current.sucess)
			ret = 0;
		printf("Testing %s\n", tests[i].name);
		printf(	"-----------------------------------------\n");
		printresult(tests[i],current,printAll);
		if (!current.sucess)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
		i++;
	}
	return ret;
}
