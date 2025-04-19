/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:03:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/17 19:33:52 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void *freearr(char ***arr, int lastindex)
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
				return(freearr(&ret,h));				
		}
		ret[h] = NULL;
	}
	return (ret);
}
