/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:52:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 13:32:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

void	print_ptr(void *ptr, int *counter)
{
	h_print_str("0x", counter);
	h_print_ulong_base((unsigned long)ptr, "0123456789abcdef", counter);
}