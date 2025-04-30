/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:54 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 12:11:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

static void print(unsigned int i)
{
	char	c;
	if (i > 9)
		print(i / 10);
	c = i % 10 + '0';
	print_char
}
//•%u Prints an unsigned decimal (base 10) number.
void print_unsigned(unsigned int i, int *counter)
{
	h_addtocounter(counter, i);
	print(i);
}