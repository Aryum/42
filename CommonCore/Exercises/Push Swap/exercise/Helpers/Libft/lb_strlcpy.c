/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lb_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:27:56 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:27:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lb.h"

size_t	lb_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	retval;

	i = 0;
	retval = lb_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (retval);
}
