#include "test_atoi.h"

#include <stdlib.h>
#include "libft.h"

typedef struct func
{
	char *name;
	int result;
} t_func;

static t_func create(char *name, int result)
{
	t_func ret;
	ret.name = name;
	ret.result = result; 
}
int main(int argc, char** agrv)
{
	int(*f_atoi[2])(const char *) = {atoi, ft_atoi};

	t_func funcs[] =
	{
		create("Atoi", atoi_logMessages(f_atoi, argc != 1)),
	};
}