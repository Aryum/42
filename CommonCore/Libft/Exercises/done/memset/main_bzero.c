#include "libft.h"
#include "tests_memset.h"
void *test_base(void* ptr,int c,size_t size)
{
	bzero(ptr,size);
	return ptr;
}

void *test_mine(void* ptr,int c,size_t size)
{
	ft_bzero(ptr,size);
	return ptr;
}
int main(int agrc, char **argv)
{
	mem_logMessages(test_base, test_mine, agrc != 1);
	return 0;
}