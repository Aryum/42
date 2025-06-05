/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lb_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:18:00 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:18:00 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lb.h"

void	*lb_calloc(size_t nmemb, size_t size)
{
	void	*retval;
	size_t	totalsize;

	totalsize = nmemb * size;
	if (size > 0 && totalsize / size != nmemb)
		return (malloc(0));
	retval = malloc(totalsize);
	if (retval != NULL)
		lb_bzero(retval, totalsize);
	return (retval);
}
