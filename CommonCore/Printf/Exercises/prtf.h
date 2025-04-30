/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:56:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 12:58:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRTF_H
# define PRTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include "print.h"

#pragma region Helpers
size_t	h_strlen(const char *s);

void	h_put_char(int c, int *counter);

void	h_put_str(char *str, int *counter);

void	h_print_nbrbase(unsigned long int nbr, char *base, int *counter);
#pragma endregion

#pragma region Print

#pragma endregion
#endif
