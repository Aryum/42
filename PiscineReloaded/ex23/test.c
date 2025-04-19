#include "ft_point.h"
#include "ft_point.h"

#include <stdio.h>


void set_point(struct s_point *point)
{
	point->x = 42;
	point->y = 21;	
}
int main(void)
{
	t_point point;
	printf("x %d\ny %d\n", point.x, point.y);
	set_point(&point);
	printf("x %d\ny %d\n", point.x, point.y);
	return (0);
}