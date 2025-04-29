/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:54 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 11:25:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//•%u Prints an unsigned decimal (base 10) number.
void print_unsigned(int i)
{
	if (i > 9)
		print(i / 10);
	ft_putchar_fd(i % 10 + '0', 1);
}