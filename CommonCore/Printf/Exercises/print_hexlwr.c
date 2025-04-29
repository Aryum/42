/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexlwr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:26:29 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 13:31:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

//•%x Prints a number in hexadecimal (base 16) lowercase format.
void print_hexlwr(unsigned int i, int *counter)
{
	h_print_ulong_base((unsigned long)i, "0123456789abcdef",counter);
}