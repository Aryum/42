/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:01:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_c;
	const char	*src_c;

	i = 0;
	dest_c = (char *)dest;
	src_c = (const char *)src;
	if (dest_c > src_c)
	{
		while (i != n)
		{
			dest_c[n - i - 1] = src_c[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	}
	return (dest_c);
}
