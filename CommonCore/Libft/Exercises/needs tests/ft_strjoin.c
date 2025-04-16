/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:58:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/16 16:58:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int i;
	unsigned int s1_len;
	char *retval;

	i = 0;
	s1_len = ft_strlen(s1);
	retval = ft_calloc(s1_len + ft_strlen(s2) + 1, sizeof(char));
	if(retval != NULL)
	{
		while (s1[i] != '\0')
		{
			retval[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			retval[s1_len + i] = s2[i];
			i++;
		}
		retval[s1_len + i] = '\0';
	}
	return (retval);
}