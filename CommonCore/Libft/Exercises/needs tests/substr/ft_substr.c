/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:09:06 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/16 14:49:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*retval;
	size_t	retsize;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (start > size)
		return (NULL);
	if (size - start > len)
		retsize = len + 1;
	else
		retsize = size - start + 1;
	retval = ft_calloc(retsize, sizeof(char));
	if (retval != NULL)
	{
		while (s[start + i] != '\0' && i < retsize)
		{
			retval[i] = s[start + i];
			i++;
		}
		retval[i] = '\0';
	}
	return (retval);
}
