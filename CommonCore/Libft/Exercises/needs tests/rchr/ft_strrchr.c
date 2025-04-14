/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:22:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/12 02:25:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	
	i = ft_strlen(s);
	if (s[i + 1] == c)
		return (&(s[i + 1]));
	while (i >= 0)
	{
		if (s[i + 1] == c)
			return (&(s[i + 1]));
		i--;
	}
	return (NULL);
}