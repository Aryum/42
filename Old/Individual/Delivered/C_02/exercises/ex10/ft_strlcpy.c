/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:50:33 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 12:50:36 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;
	unsigned int	src_size;

	counter = 0;
	src_size = ft_strlen(src);
	if (size != 0)
	{
		while (counter < src_size && counter < size - 1)
		{
			dest[counter] = src[counter];
			counter++;
		}
		dest[counter] = '\0';
	}
	return (src_size);
}
/*
#include<bsd/string.h>
#include<stdio.h>
int	main(void)
{
	char  source[14] = "Hello everyone";
	char 	dest[3];
	char  source1[] = "Hello everyone";
	char 	dest1[3];
	char 	buff[13];

	//size is 14
	unsigned int sizeDefault = strlcpy(dest1,source1, sizeof(buff));
	//size is 15
	unsigned int sizeMine = ft_strlcpy(dest,source, sizeof(buff));
	printf("\n%s",dest1);
	printf("\n%d  default",sizeDefault );
	printf("\n%s",dest);
	printf("\n%d  mine",sizeMine );
}
*/