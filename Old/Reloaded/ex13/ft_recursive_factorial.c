/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:20:54 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 17:28:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 13)
		return (0);
	else if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>
#include <time.h>
int main()
{
	printf("%d", ft_recursive_factorial(13));	
}
*/
