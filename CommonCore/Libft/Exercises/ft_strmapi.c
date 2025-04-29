/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:33:28 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 20:29:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ret = ft_strdup(s);
	i = 0;
	if (ret != NULL && f != NULL)
	{
		while (ret[i] != '\0')
		{
			ret[i] = f(i, ret[i]);
			i++;
		}
	}
	return (ret);
}
