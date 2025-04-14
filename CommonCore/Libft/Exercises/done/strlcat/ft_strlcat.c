/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/14 18:56:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t h;
	size_t srclen;
	size_t retval;
	
	i = 0;
	h = ft_strlen(dst);
	srclen = ft_strlen(src);
	retval = h + srclen;
	if (h > size)
		return (srclen + size);
	while (h < size && src[i] != '\0')
	{
		if (h != size - 1 )
			dst[h] = src[i];
		h++;
		i++;
	}
	dst[h] = '\0';
	return (retval);
}
