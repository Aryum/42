/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:29 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 19:17:46 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//•%i Prints an integer in base 10.
void print_base_ten(int i, int *counter)
{
	h_addtocounter(counter, h_count_nbr(i));
	ft_putnbr_fd(i,1);
}
