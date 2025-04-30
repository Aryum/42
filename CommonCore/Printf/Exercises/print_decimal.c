/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:07 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 18:10:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

//•%d Prints a decimal (base 10) number.
void	print_decimal(int i, int *counter)
{
	h_addtocounter(counter, h_count_nbr(i));
	ft_putnbr_fd(i,1);
}