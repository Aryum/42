
#include "libft.h"
#include "test_strnstr.h"
#include  <ctype.h>
#include <bsd/string.h>
#include <string.h>

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *) big);
	if (ft_strlen(little) > len)
		return (NULL);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
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
	char *(*func[2])(const char *, const char *, size_t) = {strnstr,ft_strnstr};
	strnstr_logMessages(func, argc != 1);
}
