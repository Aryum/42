/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo-santos <ricardo-santos@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:40:28 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/07 10:50:59 by ricardo-san      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	
	while(i < length)
	{
		f(tab[i]);
		i++;
	}
}

#include <stdio.h>
void test(int a)
{
	printf("%d\n", a);
}

int main()
{
	int arr[] = {1,2,3,4};
	ft_foreach(&arr[0], 4,test);	
}