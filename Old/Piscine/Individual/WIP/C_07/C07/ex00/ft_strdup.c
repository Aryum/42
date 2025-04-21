/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:48:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/12 12:59:20 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_size(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		length;
	int		i;

	length = str_size(src) + 1;
	dst = malloc((sizeof(char)) * length);
	if (dst != ((void *)0))
	{
		i = 0;
		while (i < length)
		{
			dst[i] = src[i];
			i++;
		}
		return (dst);
	}
	return ((void *)0);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{

	char *str1 = "WWWW";
	char *str3 = strdup(str1);
	printf("%s String\n", str3);
	printf("%p source pointer\n", str1);
	printf("%p dest pointer\n", str3);
	printf("Default\n\n");

	char *str4 = ft_strdup(str1);
	printf("%s String\n", str4);
	printf("%p source pointer\n", str1);
	printf("%p dest pointer\n", str4);
	printf("Mine\n\n");
	return (0);

}
*/