/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:57:25 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/01 14:31:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void h_put_uint(unsigned int i, int *counter)
{
	if (i > 9)
		h_put_uint(i / 10, counter);
	h_putchar(i % 10 + '0', counter);
}