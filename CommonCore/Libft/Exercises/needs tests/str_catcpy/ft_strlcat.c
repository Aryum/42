/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/14 18:39:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include <stdio.h>
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int h;
	int srclen;
	
	i = 0;
	h = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (srclen + h > size)
		return (srclen + size);
	printf("I am running");
	while (h < size - 1 && src[i] != '\0')
	{
		dst[h] = src[i];
		h++;
		i++;
	}
	dst[h] = '\0';

	return (h);
}
