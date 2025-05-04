/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:07:54 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/04 13:05:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_put_ptr(void *ptr, int *counter)
{
	if (ptr == NULL)
		h_put_str("(nil)",counter);
	else
	{
		h_put_str("0x", counter);
		h_put_ulongbase((unsigned long long)ptr, "0123456789abcdef", counter);
	}
}