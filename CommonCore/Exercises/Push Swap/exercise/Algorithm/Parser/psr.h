/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:27:05 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 14:44:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSR_H
# define PSR_H

# include "../_Headers/alg.h"

# include "../../Helpers/Lib/lib.h"

int		psr_h_try_add_number(t_stack *stack, int nbr);

int		psr_h_try_get_number(char *c, long *nbr);

void	psr_h_indexer(t_list *lst);

int		psr_agrs(t_stack *stack, int argc, char **argv);

int		print_f(const char *string, ...);

#endif