/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:14:58 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/29 16:15:00 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			j = 0;
			while (to_find[j] != '\0' && str[i + j] == to_find[j])
			{
				j++;
			}
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
			i ++;
		}
		return (((void *)0));
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char s1[] = "Hello World!";
	char s2[] = "Wol!"; 

	printf("%s return value of default\n", strstr(s1,s2));

	printf("%s retrun value of mine\n", ft_strstr(s1,s2));

	return 0;
}
*/