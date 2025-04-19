/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:49:18 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 11:33:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*ret_val;

	i = 0;
	len = ft_strlen(src);
	ret_val = malloc((len + 1) * sizeof(char));
	if (ret_val != (void *)0)
	{
		while (i < len)
		{
			ret_val[i] = src[i];
			i++;
		}
		ret_val[i] = '\0';
	}
	return (ret_val);
}
