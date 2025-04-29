/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:56:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 13:34:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRTF_H
# define PRTF_H
# include <stdarg.h>
# include "libft.h"

int		h_count_nbr(long int nbr);

void	h_print_ulong_base(unsigned long int nbr, char *base, int *counter);

void	h_print_str(char *str, int *counter);

void	print_base_ten(int i, int *counter);

void	print_char(char c, int *counter);

void	print_decimal(int i, int *counter);

void	print_hexlwr(unsigned long i, int *counter);



#endif
