#include "libft.h"
#include "tests_memset.h"
void *bzero_base(void* ptr,int c,size_t size)
{
	bzero(ptr,size);
	return ptr;
}

void *bzero_mine(void* ptr,int c,size_t size)
{
	ft_bzero(ptr,size);
	return ptr;
}
int main(int agrc, char **argv)
{
	void * (*f_bzero[2])(void *, int, size_t) = {bzero_base,bzero_mine};
	mem_logMessages(bzero_base, bzero_mine, agrc != 1);
	return 0;
}