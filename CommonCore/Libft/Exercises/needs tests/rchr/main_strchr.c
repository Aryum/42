#include "test_rchr.h"
#include "libft.h"

void * convert_base(const void *ptr,int c, size_t size)
{
	return (strchr((char *)ptr,c));
}

void * convert_mine(const void *ptr,int c, size_t size)
{
	return (ft_strchr((char *)ptr,c));
}

int main(int argc, char** agrv)
{
	rchr_logMessages(convert_base,convert_mine, argc != 1);
}