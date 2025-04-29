/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexupr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:27:26 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 11:13:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

//•%X Prints a number in hexadecimal (base 16) uppercase format.
void print_hexupr(unsigned int i)
{
	char *str;

	str =  uint_tobase(i, "0123456789ABCDEF");
	ft_putstr_fd(str, 1);
	free(str);
}