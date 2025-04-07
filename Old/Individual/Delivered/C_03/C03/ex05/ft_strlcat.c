/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:58:49 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/29 16:58:51 by ricsanto         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	source_size;
	unsigned int	i;

	dest_size = arr_size(dest);
	source_size = arr_size(src);
	i = 0;
	if (size <= dest_size)
	{
		return (size + source_size);
	}
	while (src[i] != '\0' && dest_size + i < size -1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + source_size);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	char dest[] = "Teste de ";
	char source[] = "avaliacao"; 
	char buff[15]; 
	char dest1[] = "Teste de ";
	char source1[] = "avaliacao"; 
	int size = strlcat(dest,source,sizeof(buff));
	printf("%s  size= %d return value of default\n", dest,size);
	int size1 = ft_strlcat(dest1,source1,sizeof(buff));
	printf("%s  size= %d retrun value of mine\n", dest1, size1);

	return 0;
}
*/