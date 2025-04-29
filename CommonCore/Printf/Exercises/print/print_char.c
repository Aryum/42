/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:24:03 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 19:17:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//•%c Prints a single character.
void print_char(char c, int *counter)
{
	h_addtocounter(counter, 1);
	ft_putchar_fd(c,1);
}