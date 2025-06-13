/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:19:11 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/13 17:33:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../../Helpers/Lst/lst.h"

typedef struct s_stack
{
	t_list	*lst;
	int		size;
	char	id;
} t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
} t_data;

#endif