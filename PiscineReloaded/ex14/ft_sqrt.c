/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:19:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/04 16:11:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_sqrt(int nb)
{
	int returnVal;
	int test;
	
	returnVal = 0;
	test = (returnVal + nb) / 2;
	if(nb < 0)
		return 0;
	while( test < returnVal)
	{
		if(returnVal * returnVal == nb)
			return returnVal;
		returnVal ++;
	}

	return 0;
}

#include <stdio.h>
int main()
{
	printf("%d", ft_sqrt(2147483647));
}