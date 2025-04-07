/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:52:13 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/12 13:23:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long int	delta;
	int			i;

	i = 0;
	delta = max - min;
	if (delta <= 0)
	{
		*range = ((void *)0);
		return (0);
	}
	*range = malloc(delta * sizeof(int));
	if (*range != ((void *)0))
	{
		while (i < delta)
		{
			(*range)[i] = min + i;
			i++;
		}
		return (delta);
	}
	return (-1);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int min = -114;
	int max = -1000;
	int *arr;

	int result = ft_ultimate_range(&arr,min, max);
	if( result != -1 && result != 0)
	{

		while(i < result)
		{
			printf("%d index is %d\n", i, *arr);
			arr++;
			i++;
		}
		printf("Total size %d", result);
	}
	else
	{
		printf("there was a problem with the delta or alocating memory");
	}	 
	return 0;
}
*/