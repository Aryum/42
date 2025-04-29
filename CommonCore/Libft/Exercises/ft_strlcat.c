/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/15 10:46:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	h;
	size_t	srclen;

	srclen = ft_strlen((char *)src);
	if (size == 0)
		return (srclen + size);
	i = 0;
	h = ft_strlen(dst);
	if (h + 1 > size)
		return (srclen + size);
	while (h < size - 1 && src[i] != '\0')
	{
		dst[h] = src[i];
		h++;
		i++;
	}
	dst[h] = '\0';
	return (h + srclen);
}
