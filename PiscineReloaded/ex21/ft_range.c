/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:20:51 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 11:34:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret_val;
	int	i;

	if (min >= max)
		return ((void *)0);
	ret_val = malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		ret_val[i] = min;
		i ++;
		min ++;
	}
	return (ret_val);
}

/*
#include<stdio.h>
int main()
{
	int i = 0;
	int min = 0;

	int max = 9;
	int *arr = ft_range(min, max);
	while(i < max-min)
	{
		printf("%d\n", arr[i]);		
		i++;
	}
}
*/