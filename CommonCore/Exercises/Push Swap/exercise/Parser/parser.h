/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:27:05 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 12:44:54 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER
# define PARSER

#include "./Helpers/Lst/lst.h"

int try_add_number(t_list **lst, int nbr);

int	try_get_number(char *c, long *nbr);

#endif