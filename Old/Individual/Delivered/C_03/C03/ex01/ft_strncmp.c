/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:59:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/29 14:59:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while ((*s1 != '\0' || *s2 != '\0') && counter < n)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1 ++;
		s2 ++;
		counter++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = "Test";
	char s2[] = "Teste"; 
	int n = 5;
	int	ret = strncmp(s1,s2,n);
	printf("%d retrun value of default\n", ret);

	ret = ft_strncmp(s1,s2,n);
	printf("%d retrun value of mine", ret);

	return 0;
}
*/