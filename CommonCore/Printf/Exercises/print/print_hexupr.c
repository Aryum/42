/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexupr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:27:26 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 13:31:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

//•%X Prints a number in hexadecimal (base 16) uppercase format.
void print_hexupr(unsigned int i, int *counter)
{
	h_print_ulong_base((unsigned long)i, "0123456789ABCDEF",counter);
}