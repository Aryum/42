#include "libft.h"
#include "test_strlcpy .h"
#include  <ctype.h>

size_t ft_strlen(const char *s)
{
	int	i;
	
	i = 0;
	while(s[i] != '\0')
		i++;		
	return (i);
}

int main(int argc, char ** agrv)
{
	strcatcpy_logMessages(strlcpy,ft_strlcpy, argc != 1);
}
