/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lb_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:27:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:27:52 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lb.h"

char	*lb_strdup(const char *s)
{
	char	*retval;
	size_t	i;

	i = 0;
	retval = lb_calloc(lb_strlen(s) + 1, sizeof(char));
	if (retval != NULL)
	{
		while (s[i] != '\0')
		{
			retval[i] = s[i];
			i++;
		}
		retval[i] = '\0';
	}
	return (retval);
}
