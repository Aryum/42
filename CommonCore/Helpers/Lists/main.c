#include "lst.h"
#include <stdio.h>
#include <stdlib.h>
void print(char * c)
{
	printf(c);
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
	t_list *list = lst_new("Hello");

	lst_add_back(&list,lst_new("world"));

	lst_iter(&list,print);

	lst_clear(&list, free);
}