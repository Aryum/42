/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/29 15:56:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arr_size(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				dest_size;
	unsigned int	counter;

	dest_size = arr_size(dest);
	counter = 0;
	while (src[counter] != '\0' && counter < nb)
	{
		dest[dest_size + counter] = src[counter];
		counter++;
	}
	dest[dest_size + counter] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = " de avaliacao";
	char s2[50] = "Teste"; 
	char s3[] = " de avaliacao";
	char s4[50] = "Teste"; 

	printf("%s return value of default\n", strncat(s2,s1, 12));

	printf("%s retrun value of mine\n", ft_strncat(s4,s3, 12));

	return 0;
}
*/