/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:52:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/09 12:28:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1 ++;
		s2 ++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = "Teste";
	char s2[] = "Wall"; 

	int	ret = strcmp(s1,s2);
	printf("%d retrun value of default\n", ret);

	ret = ft_strcmp(s1,s2);
	printf("%d retrun value of mine\n", ret);

	printf("%c s1 pointer1 value\n", *s1);
	printf("%c s2 pointer2 value\n", *s2);
	return 0;
}
*/