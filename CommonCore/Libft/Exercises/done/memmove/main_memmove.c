#include "libft.h"
#include "test_memmove.h"
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

int main(int argc, char ** agrv)
{
	void*(*funcs[2])(void *, const void *, size_t ) = {memmove,ft_memmove};
	memmove_logMessages(funcs, argc != 1);
}
