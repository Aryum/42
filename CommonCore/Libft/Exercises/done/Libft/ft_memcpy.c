/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:31:10 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/14 17:08:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_c;
	const unsigned char	*src_c;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_c = (unsigned char *)dest;
	src_c = (const unsigned char *)src;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}
