#include "test_atoi.h"
#include <stdlib.h>
#include "libft.h"

static int isclass(int c, int lower, int upper)
{
	return(c >= lower && c <= upper);
}

int ft_isdigit(int c)
{
	if(isclass(c, '0', '9'))
		return (2048);	
	return (0);
}


int main(int argc, char ** agrv)
{
	int(*func[2])(const char *) = {atoi, ft_atoi};
	atoi_logMessages(func, argc != 1);
}