
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
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;
	int retval;
	
	i = 0;
	retval = ft_strlen(dst) + ft_strlen(src);
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return  (retval);
}
char *ft_strdup(const char *s)
{
	char *retval;
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(s);
	retval = ft_calloc(len + 1, sizeof(char));
	if(retval != NULL)
	{
		while (s[i] != '\0')
		{
			retval[i] = s[i];
			i++;
		}
		retval[i] = '\0';
	}
	return (retval);
}
int main(int argc, char ** agrv)
{
	substr_logMessages(ft_substr,argc != 1);
}