/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:28:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/17 13:17:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ischarset(char c, char const *set)
{
	unsigned int i;

	i = 0;
	if(set != NULL)
	{
		while (set[i] != '\0')
		{
			if (c == set[i])
				return (1);
			i++;
		}
	}
	return (0);
}

static int charsetcount(char const *s1, char const *set)
{
	unsigned int size;
	unsigned int retval;

	retval = 0;
	size = ft_strlen(s1);
	while (s1[retval] != '\0' && ischarset(s1[retval],set))
		retval ++;
	if (retval != size)
	{
		while(size >= 0 && ischarset(s1[size - 1], set))	
		{
			size --;
			retval++;
		}
	}
	return  (retval);
}
char *ft_strtrim(char const *s1, char const *set)
{
	char *retval;
	unsigned int i;
	unsigned int h;
	unsigned int newlen;
	
	if (s1 == NULL)
		return (NULL);
	h = 0;
	i = 0;
	newlen = ft_strlen(s1) - charsetcount(s1,set) + 1;
	retval = ft_calloc(newlen, sizeof(char));
	if(retval != NULL)
	{
		while(s1[i] != '\0' && ischarset(s1[i],set))
			i++;
		while (h < newlen - 1)
		{
			retval[h] = s1[i];
			i++;
			h++;
		}
		retval[h] = '\0';
	}
	return (retval);
}