/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:28:48 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:28:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	lib_bzero(void *s, size_t n)
{
	lib_memset(s, '\0', n);
}
