#include "tests_cmp.h"
#include "libft.h"


int main(int argc, char ** agrv)
{
	cmp_logMessages(memcmp,ft_memcmp, argc != 1);
}
