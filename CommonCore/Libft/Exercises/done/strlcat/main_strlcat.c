#include "libft.h"
#include "test_strlcat.h"
#include  <ctype.h>
#include <string.h>
size_t ft_strlen(const char *s)
{
	int	i;
	
	i = 0;
	while(s[i] != '\0')
		i++;		
	return (i);
}
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	strlcat(char *dst, const char *src, size_t size);


int main(int argc, char ** agrv)
{
	strcatcpy_logMessages(strlcat,ft_strlcat, argc != 1);
}
