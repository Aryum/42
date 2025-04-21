/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:51 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/01 15:16:52 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive(int index)
{
	if (index > 0)
	{
		if (index == 1)
		{
			return (1);
		}
		else
		{
			return (recursive(index - 1) + recursive(index - 2));
		}
	}
	return (0);
}

int	ft_fibonacci(int index)
{
	if (index >= 0)
		return (recursive(index));
	else
		return (-1);
}

/*
#include <stdio.h>

int	main()
{
	int index = 10;

	printf("At index %d fibonacci is %d", index, ft_fibonacci(index));

	return 0;
}
*/