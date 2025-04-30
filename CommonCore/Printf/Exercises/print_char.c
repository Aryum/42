/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:24:03 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 11:49:27 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//•%c Prints a single character.
void print_char(int c, int *counter)
{
	h_addtocounter(counter, 1);
	write(1, &c, 1);
}