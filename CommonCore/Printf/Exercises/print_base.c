/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:29 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 13:36:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//•%i Prints an integer in base 10.
void print_base_ten(int i, int *counter)
{
	(*counter) = h_count_nbr((long)i);
	ft_putnbr_fd(i,1);
}
