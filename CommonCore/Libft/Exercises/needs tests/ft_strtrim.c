/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:28:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/16 17:59:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ischarset(char c, char const *set)
{
	unsigned int i;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int charsetcount(char const *s1, char const *set)
{
	unsigned int i;
	unsigned int h;
	unsigned int retval;

	i = 0;
	retval = 0;
	while (s1[i] != '\0')
	{
		if (ischarset(s1[i], set))
			retval ++;
		i++;
	}	
	
	return  (retval);
}
char *ft_strtrim(char const *s1, char const *set)
{
	char *retval;
	unsigned int i;
	unsigned int h;
	unsigned int trimmedlen;
	
	if (s1 == NULL)
		return (NULL);
	h = 0;
	i = 0;
	trimmedlen = ft_strlen(s1) - charsetcount(s1,set);
	retval = ft_calloc(trimmedlen + 1, sizeof(char));
	if(retval != NULL)
	{
		while(s1[i] != '\0')
		{
			if(!ischarset(s1[i],set))
			{
				retval[h] = s1[i];
				h++;
			}
			i++;
		}
		retval[h] = '\0';
	}
	return (retval);
}