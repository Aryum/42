/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:31:10 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/14 15:07:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void * dest, const void *src, size_t n)
{
	unsigned char *dest_c;
	const unsigned char *src_c;
	size_t	i;

	dest_c = (unsigned char *)dest;
	src_c = (const unsigned char *)src;

	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}