/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:07:54 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 13:08:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

void	h_put_ptr(void *ptr, int *counter)
{
	h_print_str("0x", counter);
	h_print_ulong_base((unsigned long)ptr, "0123456789abcdef", counter);
}