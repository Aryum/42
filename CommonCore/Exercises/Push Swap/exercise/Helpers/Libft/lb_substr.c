/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lb_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:28:14 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:28:14 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lb.h"

char	*lb_substr(char const *s, unsigned int start, size_t len)
{
	char	*retval;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = lb_strlen(s);
	if (start >= size)
		return (lb_strdup(""));
	if (len > size - start)
		len = size - start ;
	retval = lb_calloc(len + 1, sizeof(char));
	if (retval != NULL)
		lb_strlcpy(retval, &s[start], len + 1);
	return (retval);
}
