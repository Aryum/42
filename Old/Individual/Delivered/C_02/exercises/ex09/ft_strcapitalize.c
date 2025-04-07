/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:29:38 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 12:29:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	capitalize_ltr(char *str)
{
	if (*str >= 'a' && *str <= 'z' )
	{
		*str -= 32;
	}
}

void	lowercase_ltr(char *str)
{
	if (*str >= 'A' && *str <= 'Z' )
	{
		*str += 32;
	}
}

int	check_word_start(char last_char)
{
	if (last_char >= 'A' && last_char <= 'Z')
	{
		return (0);
	}
	if (last_char >= 'a' && last_char <= 'z')
	{
		return (0);
	}
	if (last_char >= '0' && last_char <= '9')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (counter == 0 || check_word_start(str[counter - 1]))
		{
			capitalize_ltr(&str[counter]);
		}
		else
		{
			lowercase_ltr(&str[counter]);
		}
		counter++;
	}
	return (str);
}
/*
#include<stdio.h>
int	main(void)
{
	char	c[] = "ola, /tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";
	ft_strcapitalize(c);
	printf("%s", c);
}
*/