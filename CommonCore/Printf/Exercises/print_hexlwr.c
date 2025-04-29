/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexlwr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:26:29 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 11:14:27 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//•%x Prints a number in hexadecimal (base 16) lowercase format.
//just use to upper to print %X
void print_hexlwr(int i)
{
	char *str;

	str =  uint_tobase(i, "0123456789abcdef");
	ft_putstr_fd(str, 1);
	free(str);
}