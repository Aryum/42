#include "libft.h"
#include "tests_memset.h"

int main(int agrc, char **argv)
{
	mem_logMessages(memset, ft_memset, agrc != 1);
	return 0;
}