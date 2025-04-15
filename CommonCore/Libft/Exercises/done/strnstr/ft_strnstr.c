/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:28:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/15 14:37:16 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strnstr(const char *big, const char *little, size_t len)
{
	char *retval;
	unsigned int i;
	unsigned int h;

	i = 0;
	if(little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len )
	{
		h = 0;
		while (little[h] != '\0' && big[i + h] == little[h] && i + h < len)
			h++;
		if(little[h] == '\0')
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);

}