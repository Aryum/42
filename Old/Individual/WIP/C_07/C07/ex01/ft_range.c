/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:50:19 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/12 13:23:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*ret_val;
	long int	delta;
	int			i;

	delta = max - min;
	if (delta > 0)
	{
		ret_val = malloc(delta * sizeof(int));
		if (ret_val != ((void *)0))
		{
			i = 0;
			while (i < delta)
			{
				ret_val[i] = min + i;
				i++;
			}
			return (ret_val);
		}
	}
	return ((void *)0);
}

/*
#include <stdio.h>
int main()
{

	int i = 0;
	int min = -10;
	int max = -1;
	int *arr = ft_range(min, max);

	while(i < max - min)
	{
		printf("%d index is %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return 0;
}
*/