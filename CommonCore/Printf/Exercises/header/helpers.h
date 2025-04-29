/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:34:56 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 19:36:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

void	h_addtocounter(int *counter, int value);

int		h_count_nbr(long int nbr);

void	h_print_nbrbase(unsigned long int nbr, char *base, int *counter);

void	h_print_str(char *str, int *counter);

#endif