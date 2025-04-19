/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:57 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/27 16:54:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (src[counter] != '\0' && counter < n)
	{
		dest[counter] = src[counter];
		counter++;
	}
	while (counter < n)
	{
		dest[counter] = '\0';
		counter++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int size = 10;

	char source1[3] = "abc";
	char dest1[20] = {0};
	
	printf("Is null terminated? %s\n", (dest1[size-1] == '\0' ? "yes" : "no"));
	printf("\n%s \nsize: %lu Mine \n", 
	ft_strncpy(dest1,source1,size), sizeof(dest1));	
	char source2[3] = "abc";
	char dest2[20] = {0};
	

	printf("\nIs null terminated? %s\n", (dest2[size-1] == '\0' ? "yes" : "no"));
	printf("\n%s \nsize: %lu default\n", 
	strncpy(dest2,source2, size), sizeof(dest2));
	return (0);
}
*/