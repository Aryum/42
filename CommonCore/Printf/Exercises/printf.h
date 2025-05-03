/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:56:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/03 12:56:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

void	h_put_char(int c, int *counter);

void	h_put_int(int n, int *counter);

void	h_print_nbrbase(unsigned long int nbr, char *base, int *counter);

void	h_put_ptr(void *ptr, int *counter);

void	h_put_str(char *str, int *counter);

void	h_put_uint(unsigned int i, int *counter);

int		h_strlen(const char *s);

int		h_count_args(const char *str);

int		ft_printf(const char *string, ...);

#endif
