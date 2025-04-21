/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:09:33 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 11:28:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

/*
#include<stdio.h>
#include<string.h>
int main()
{
	char *test1 = "tes";
	char *test2 = "te";

	printf("Default %d\n", strcmp(test1,test2));
	printf("Mine %d", strcmp(test1,test2));

}*/