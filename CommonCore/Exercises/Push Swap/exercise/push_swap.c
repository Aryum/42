#include "push_swap.h"

void print(int i)
{
	print_f("%d\n", i);
}
int main(int argc, char **argv)
{
	t_list *lst = NULL;

	psr_agrs(&lst,argc,argv);

	lst_iter(lst, print);
	lst_clear(&lst); 
}