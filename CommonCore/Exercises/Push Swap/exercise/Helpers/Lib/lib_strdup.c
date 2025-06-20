/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:27:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:27:52 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*lib_strdup(const char *s)
{
	char	*retval;
	size_t	i;

	i = 0;
	retval = lib_calloc(lib_strlen(s) + 1, sizeof(char));
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
