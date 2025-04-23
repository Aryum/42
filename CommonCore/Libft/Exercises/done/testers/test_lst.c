#include "libft.h"
#include <stdio.h>

typedef struct lst_test
{
	char *name;
	t_list *myOut;
	t_list *expectedOut;
	t_list *newLst;
	int hasCpy;
	int count;
} t_lst_test;

typedef struct strcmp_ret
{
	int sucess;
	unsigned int index;

} t_strcmp_ret;

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
	
	retVal.sucess = a[i] == b[i];
	retVal.index = retVal.sucess ? 0 : i;
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

t_list *createlst(char **content)
{
	int i = 0;
	t_list *start =  NULL;
	t_list *last =  NULL;
	while(!strComp(content[i], "LAST").sucess)
	{
		t_list *current = ft_lstnew(createstr(content[i]));
		if (current != NULL)
		{
			if(start == NULL)
				start = current;
			if(last != NULL)
				(*last).next = current;
			last = current;
		}
		else
		{
			printf("%s failed to create\n", content[i]);
			break;
		}
		i++;
	}
	return start;
}

static t_lst_test createlst_test(char **lst, char **out, char *name)
{
	t_lst_test ret;
	ret.myOut = createlst(lst);
	ret.expectedOut = createlst(out);
	ret.name = name;
	ret.count = 0;
	ret.hasCpy = 0;
	ret.newLst = NULL;
	while (!strComp(out[ret.count + 1], "LAST").sucess)
		ret.count++;
	ret.count++;

	return ret;
}

static void printlst(t_lst_test test)
{
	int i = 0;
	t_list *myOut = test.myOut;
	t_list *expectedOut = test.expectedOut;
	while (i < test.count)
	{
		if(test.newLst != NULL)
		{
			printf("My out	(%s) | (%s)	Expected\n", (char *)(*test.newLst).content, (char *)(*expectedOut).content);
			printf("My Ptr	(%p) | (%p)	Og Ptr\n\n", myOut, test.newLst);
			test.newLst =(*test.newLst).next;
		}
		else
		{
			printf("My	(%s) | (%s)	Expected\n", (char *)(*myOut).content, (char *)(*expectedOut).content);
		}
		myOut = (*myOut).next;
		expectedOut = (*expectedOut).next;
		i++;
	}
	printf("\n");
}

static int comparelst(t_lst_test test)
{
	int i = 0;
	t_list *myOut = test.myOut;
	t_list *expectedOut = test.expectedOut;
	while (i < test.count)
	{
		if(!strComp((char *)(*myOut).content, (char *)(*expectedOut).content).sucess)
			return 0;
		myOut = (*myOut).next;
		expectedOut = (*expectedOut).next;
		i++; 
	}
	return 1;
}

static void iterFunc(void *c)
{
	char *l = (char *)c;
	*l += 1; 
}


static void *mapiFunc(void *c)
{
	char *ret = createstr(c);
	*ret += 1;
	return ret; 
}
static int comparelst_mapi(t_lst_test test)
{
	int i = 0;
	while (i < test.count)
	{
		if(test.myOut == test.newLst)
			return 0;
		if(!strComp((char *)(*test.expectedOut).content, (char *)(*test.newLst).content).sucess)
			return 0;
		test.myOut = (*test.myOut).next;
		test.newLst = (*test.newLst).next;
		test.expectedOut = (*test.expectedOut).next;

		i++; 
	}
	return 1;
}

static void printresult(t_lst_test test, void (*print)(t_lst_test),int result,int printAll)
{
	if(!result || printAll)
	{
		printf("Testing %s\n", test.name);
		printf(	"-----------------------------------------\n");
		if(!result || printAll)
			print(test);
		if (!result)
			printf(	"------------------ERROR------------------\n\n");
		else
			printf(	"------------------GOOD------------------\n\n");
	}

	ft_lstclear(&test.myOut,free);
	ft_lstclear(&test.expectedOut,free);
	if(test.hasCpy)
		ft_lstclear(&test.newLst,free);
}

static void testadd(char *myOut[],char *expected[],char *str,void(*func)(t_list **,t_list*), char *name, int printAll)
{
	t_lst_test test = createlst_test(myOut, expected, name);
	func(&test.myOut, ft_lstnew(createstr(str)));

	printresult(test,printlst,comparelst(test),printAll);
}
static void printlast(t_lst_test test)
{
	printf("My	(%s) | (%s)	Expected\n", (char *)(*ft_lstlast(test.myOut)).content, "3");
}
static void testlast(int printAll)
{
	t_lst_test test = createlst_test((char *[]){"1","2","3","LAST"}, (char *[]){"1","2","3","LAST"}, "Last");
	
	printresult(test,printlast,
		strComp((char *)(*ft_lstlast(test.myOut)).content, "3").sucess,printAll);
}



static void testiter(char *myOut[],char *expected[], char *name, int printAll)
{
	t_lst_test test = createlst_test(myOut, expected, name);
	ft_lstiter(test.myOut,iterFunc);
	printresult(test,printlst,comparelst(test),printAll);
}


static t_lst_test createlst_testMAPI(char **lst, char **out, char *name)
{
	t_lst_test ret;
	ret = createlst_test(lst,out,name);
	ret.newLst = ft_lstmap(ret.myOut,mapiFunc,free);
	ret.hasCpy = 1;
	return ret;
}

static void testmap(char *myOut[],char *expected[], char *name, int printAll)
{
	t_lst_test test = createlst_testMAPI(myOut, expected, name);
	printresult(test, printlst,comparelst_mapi(test),printAll);
}

static void printlen(t_lst_test test)
{
	printf("My	(%d) | (%d)	Expected\n", ft_lstsize(test.myOut),test.count);
}

static void testlen(char *myOut[], char *name, int printAll)
{
	t_lst_test test = createlst_test(myOut, myOut, name);
	printresult(test,printlen, ft_lstsize(test.myOut) == test.count,printAll);
}

int lst_logMessages(int printAll)
{
	testadd(	(char *[]){"1","2","3","LAST"},
				(char *[]) {"1","2","3","4","LAST"},
			"4", ft_lstadd_back, "Add back", printAll);
	testadd(	(char *[]){"1","2","3","LAST"},
				(char *[]) {"0","1","2","3","LAST"},
			"0", ft_lstadd_front, "Add front", printAll);
	testlast(printAll);
	testiter(	(char *[]){"1","2","3","LAST"},
				(char *[]){"2","3","4","LAST"},
			"Iterate", printAll);
	testmap(	(char *[]){"1","2","3","LAST"},
				(char *[]){"2","3","4","LAST"},
			"Mapi", printAll);
	testlen((char *[]){"1","2","3","LAST"},
			"Len", printAll);
	//lst new tested by creation
	//clear and delone is tested with valgrind
}
