/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:27:05 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 18:13:00 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSR_H
# define PSR_H

# include <stdlib.h>

# include "lib.h"

# include "lst.h"

int	psr_h_try_add_number(t_list **lst, int nbr);

int	psr_h_try_get_number(char *c, long *nbr);

int	psr_agrs(t_list **lst, int argc, char **argv);

int	print_f(const char *string, ...);

#endif