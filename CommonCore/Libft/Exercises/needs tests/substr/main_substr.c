
#include "libft.h"
#include "test_substr.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *retval;
	size_t totalsize;

	totalsize = nmemb * size;
	if (nmemb == 0)
		return (NULL);
	retval = malloc(totalsize);
	if (retval != NULL)
		bzero(retval,totalsize);
	return (retval);
}
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
	substr_logMessages(ft_substr,argc != 1);
}