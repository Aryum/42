/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:57:06 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/02 11:57:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculate_sqrt(int target, int last)
{
	int	raised;

	raised = last * last;
	if (raised == target)
	{
		return (last);
	}
	if (raised < target)
	{
		return (calculate_sqrt(target, last + 1));
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	return (calculate_sqrt (nb, 0));
}
/*
#include <stdio.h>
int main()
{
	int	nbr = 144;
	printf("The square root of %d is %d", nbr, ft_sqrt(nbr));
	return 0;
}
*/