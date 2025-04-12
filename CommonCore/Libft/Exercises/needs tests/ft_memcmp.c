/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:27:38 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/12 02:34:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int memcmp(const void *s1, const void *s2, size_t n)
{
	int i;
	int retval;
	unsigned char * s1_c = (unsigned char *)s1;
	unsigned char * s2_c = (unsigned char *)s2;

	i = 0;
	retval = 0;
	while (i < n)
	{
		retval += s1_c[i] - s2_c[i];  
		i++;
	}
	return (retval);
}
