/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:28:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/15 12:34:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strnstr(const char *big, const char *little, size_t len)
{
	char *retval;
	unsigned int i;
	unsigned int h;

	if(little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + h] == little[h])
		{
			if(little[h + 1] == '\0')
				return ((char *)&big[i]);
			h++;
		}
		i++;
	}
	return (NULL);

}