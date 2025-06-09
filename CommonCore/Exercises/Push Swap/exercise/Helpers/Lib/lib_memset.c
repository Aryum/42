/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memset.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:18:07 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:18:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*lib_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}
