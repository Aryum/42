#include "test_rchr.h"
#include "libft.h"

int main(int argc, char** agrv)
{
	rchr_logMessages(memchr,ft_memchr, argc != 1);
}