/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:48:00 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/27 11:48:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <unistd.h>
#include <string.h>
void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
int main(void)
{
	char start[6] = "start";
	char end[6] = "-----";


	ft_putstr(start);
	ft_putstr("\n");
	ft_putstr(end);
	ft_strcpy(end, start);
	write(1, "\n", 1);
	ft_putstr(end);

	write(1, "\nMine\n", 7);
	write(1 , ft_strcpy(end, start), 1);
	write(1, "\nBase\n", 7);
	write(1 , strcpy(end, start), 1);	
}
*/