/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:03:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/17 17:58:43 by ricsanto         ###   ########.fr       */
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

int countwordlen (char *s, char c)
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
	wordcount  = countwords (s, c); 
	ret = ft_calloc(wordcount + 1, sizeof(char *));
	if(ret != NULL)
	{
		while (h < wordcount)
	{
		while (s[i] == c)
			i++;
		wordlen = countwordlen(&s[i],c);		
		ret[h] = ft_strdup(ft_substr(&s[i],0,wordlen));
		if(ret[h] != NULL)
		{
			i += wordlen;
			h++;
		}
		else
		{
			//free and get out of loop
		}
	}
	ret[i] = NULL;
	}
	return (ret);
}

#include <stdio.h>

int main()
{
	char *str ="A b c d e";
	printf("Word count: %d", countwords(str,' '));
	
}