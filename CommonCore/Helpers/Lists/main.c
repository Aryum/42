#include "lst.h"
#include <stdio.h>
#include <stdlib.h>
void print(void * c)
{
	printf((char *)c);
}

char *createstr(char *c)
{
	int i = 0;
	while (c[i] != '0')
		i++;
	char *ret = malloc(i + 1);
	i = 0;
	while (c[i] != '0')
	{
		ret[i] = c[i];
		i++;
	}
	ret[i] = c[i];
	return ret;
}
int main()
{
	t_list *list = lst_new(createstr("Hello"));
	t_list *working = lst_new(createstr("I am working "));
	t_list *world = lst_new(createstr(" world"));
	t_list *goobye = lst_new(createstr(" Goodbye"));
	lst_add_front(&list,working);
	lst_add_back(&list,world);
	lst_add_back(&list,goobye);

	lst_iter(list,print);


	printf("\n\n1st NEXT ONE\n\n");
	lst_delone(&list,&world, free);
	lst_iter(list,print);
	printf("\n\n2nd NEXT ONE\n\n");
	lst_delone(&list,&goobye, free);
	lst_iter(list,print);
	printf("\n\n3rd NEXT ONE\n\n");
	lst_delone(&list,&working, free);
	lst_iter(list,print);

	lst_clear(&list, free);
}