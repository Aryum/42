#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *retval;
	size_t totalsize;

	totalsize = nmemb * size;
	if (size > 0 && totalsize / size != nmemb)
		return (malloc(0));
	retval = malloc(totalsize);
	if (retval != NULL)
		ft_bzero(retval,totalsize);
	return (retval);
}

int ft_atoi(const char *nptr)
{
	unsigned int i;
	int sign;
	int retval;

	sign = 1;
	retval = 0;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if(nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		retval += nptr[i] - '0';
		if(ft_isdigit(nptr[i + 1]))
			retval *= 10;
		i++;
	}
	return (retval * sign);
}

static int isclass(int c, int lower, int upper)
{
	return(c >= lower && c <= upper);
}

int ft_isalpha(int c)
{
	if(isclass(c, 'a', 'z') || isclass(c, 'A', 'Z'))
		return (1024);	
	return (0);
}


int ft_isalnum(int c)
{
	if(ft_isdigit(c) || ft_isalpha(c))
		return (8);
	return (0); 
}
int	ft_isascii(int c)
{
	if(isclass(c, 0, 127))
		return (1);	
	return (0);
}
int ft_isdigit(int c)
{
	if(isclass(c, '0', '9'))
		return (2048);	
	return (0);
}
int ft_isprint(int c)
{
	if(isclass(c, 32, 126))
		return (16384);	
	return (0);
}
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;
	unsigned char * s1_c = (unsigned char *)s1;
	unsigned char * s2_c = (unsigned char *)s2;

	i = 0;
	if(n == 0)
		return (0);
	while ((s1_c[i] != '\0' && s1_c[i] == s2_c[i]) && i < n - 1)
		i++;
	return (s1_c[i] - s2_c[i]);
}
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_memcmp(s1,s2,n));
}
void *ft_memcpy(void * dest, const void *src, size_t n)
{
	unsigned char *dest_c;
	const unsigned char *src_c;
	size_t	i;

	i = 0;
	dest_c = (unsigned char *)dest;
	src_c = (const unsigned char *)src;

	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	
	return (dest);

}void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	char *dest_c;
	const char *src_c;
	
	i = 0;
	dest_c = (char *)dest;
	src_c = (const char *)src;
	if (dest_c > src_c)
	{
		while (i != n)
		{
			dest_c[n - i - 1] = src_c[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	}
	return  (dest_c);
}
void *ft_memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char 	*ptr;
	
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	} 

	return ptr;
}

void ft_bzero(void *s, size_t n)
{
	ft_memset(s,'\0',n);
}

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *s_c;
	unsigned char c_c;

	i = 0;
	c_c = (unsigned char)c;
	s_c = (unsigned char*)s;
	while (i < n)
	{
		if (s_c[i] == c_c)
			return (&s_c[i]);
		i++;
	}
	return (NULL);
}

char *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if(s[i] == c)
			return ((char *)&(s[i]));
		i++;
	}
	if(s[i] == c)
		return ((char *)&(s[i]));
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

char *ft_strrchr(const char *s, int c)
{
	int i;
	
	i = ft_strlen(s);
	if (s[i + 1] == c)
		return ((char *)&(s[i + 1]));
	while (i >= 0)
	{
		if (s[i + 1] == c)
			return ((char *)&(s[i + 1]));
		i--;
	}
	return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	s1_len;
	char			*retval;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	retval = ft_calloc(s1_len + ft_strlen(s2) + 1, sizeof(char));
	if (retval != NULL)
	{
		while (s1[i] != '\0')
		{
			retval[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			retval[s1_len + i] = s2[i];
			i++;
		}
		retval[s1_len + i] = '\0';
	}
	return (retval);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t h;
	size_t srclen;
	size_t retval;
	
	i = 0;
	h = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	retval = h + srclen;
	if (h + 1 > size )
		return (srclen + size);
	while (h < size - 1 && src[i] != '\0')
	{
		dst[h] = src[i];
		h++;
		i++;
	}
	dst[h] = '\0';
	return (retval);
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

char * ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int h;

	i = 0;
	if(little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len )
	{
		h = 0;
		while (little[h] != '\0' && big[i + h] == little[h] && i + h < len)
			h++;
		if(little[h] == '\0')
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*retval;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start ;
	retval = ft_calloc(len + 1, sizeof(char));
	if (retval != NULL)
		ft_strlcpy(retval, &s[start], len + 1);
	return (retval);
}

int ft_tolower(int c)
{
	if(isclass(c, 'A', 'Z'))
		return (c + 32);
	return (c);
}

int ft_toupper(int c)
{
	if(isclass(c, 'a', 'z'))
		return (c - 32);
	return (c);
}

 void *freesplit(char ***arr, int lastindex)
{
	while (lastindex >= 0)
	{
		if(arr[lastindex] != NULL)
			free((*arr)[lastindex]);
		lastindex--;
	}
	free(*arr);
	return (NULL);
}

static unsigned int countwords(char const *s, char c)
{
	unsigned int i;
	unsigned int ret;
	int flag;
	
	i = 0;
	ret = 0;
	flag = 0;	
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			ret++;
		i++;
	}
	return (ret);
}

static int countwordlen (char *s, char c)
{
	int i;
	
	i = 0;
	while(s[i] != '\0' && s[i] != c)
		i++;
	return i;
}

char **ft_split(char const *s, char c)
{
	char ** ret;
	unsigned int wordcount;
	unsigned int wordlen;
	unsigned int i;
	unsigned int h;

	i = 0;
	h = 0;
	if(s == NULL)
		return (NULL);
	wordcount  = countwords (s, c); 
	ret = ft_calloc(wordcount + 1, sizeof(char *));
	if(ret != NULL)
	{
		while (h < wordcount)
		{
			while (s[i] == c)
				i++;
			wordlen = countwordlen((char *)&s[i],c);		
			ret[h] = ft_substr(&s[i],0,wordlen);
			if(ret[h] != NULL)
			{
				i += wordlen;
				h++;
			}
			else
				return(freesplit(&ret,h));				
		}
		ret[h] = NULL;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	long	nbr;
	
	nbr = (long)n;
	len = nbcount(nbr);
	if (nbr < 0)
		len++;
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret != NULL)
	{
		len -= 1;
		if (nbr< 0)
		{
			ret[0] = '-';
			nbr *= -1;
		}
		while (len >= 0 && ret[len] != '-')
		{
			ret[len] = nbr % 10 + '0';
			len -= 1;
			nbr /= 10;
		}
	}
	return (ret);
}
