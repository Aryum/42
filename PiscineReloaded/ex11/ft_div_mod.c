/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:54:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 10:58:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
int main()
{
	int nbr1 = 7;
	int nbr2 = 3;
	
	int div = 0;
	int mod = 0;

	ft_div_mod(nbr1,nbr2, &div, &mod);
	printf("n1 %d\nn2 %d\n", nbr1, nbr2);
	printf("div %d\nmod%d", div, mod);

}
*/