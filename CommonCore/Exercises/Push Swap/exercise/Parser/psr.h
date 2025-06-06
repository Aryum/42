/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:27:05 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:23:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSR
# define PSR

#include "./Helpers/Lst/lst.h"
#include "./Helpers/Libft/lib.h"

int psr_try_add_number(t_list **lst, int nbr);

int	psr_try_get_number(char *c, long *nbr);

int	psr_agrs(t_list **lst, int argc, char **argv);

#endif