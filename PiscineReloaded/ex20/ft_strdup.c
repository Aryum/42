/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:49:18 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/05 16:16:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}

	return i;
}

char *ft_strdup(char *src)
{
	int i;
	int len;
	char *returnVal;
	
	i = 0;

	len = ft_strlen(src);
	returnVal = malloc((len + 1) * sizeof(char));
	
	if(returnVal != (void *)0)
	{
		while(i < len)
		{
			returnVal[i] = src[i];
			i++;
		}
		returnVal[i] = '\0';
	}
	return returnVal;
}

