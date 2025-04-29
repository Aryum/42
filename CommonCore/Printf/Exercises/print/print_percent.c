/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:28:05 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 18:10:33 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

//•%% Prints a percent sign.
void	print_percent(int *counter)
{
	h_addtocounter(counter, 1);
	ft_putchar_fd('%',1);
}