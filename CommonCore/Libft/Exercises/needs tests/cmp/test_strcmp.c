#include "tests_cmp.h"
#include "libft.h"

int convert1(const void * str1,const void * str2, size_t size)
{
	if(str1 == (void *)0 || str2 == (void *)0 )
		return 1;
	else
		return ft_strncmp((char *)str1,(char *)str2, size);
}

int convert2(const void * str1,const void * str2, size_t size)
{
	if(str1 == (void *)0 || str2 == (void *)0 )
		return 1;
	else
		return strncmp((char *)str1,(char *)str2, size);
}
int main(int argc, char ** agrv)
{
	cmp_logMessages(convert1,convert2, argc != 1);
}
