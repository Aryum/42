/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:20:51 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/05 16:30:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *returnVal;
	int i;
	
	if(min >= max)
		return (void *)0;
	returnVal = malloc((max-min) * sizeof(int));
	i = 0;
	while(min < max)
	{
		returnVal[i] = min;
		i ++;
		min ++;
	}
	return returnVal;
}
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