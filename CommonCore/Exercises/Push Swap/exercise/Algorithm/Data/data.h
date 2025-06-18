/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:11:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:24:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../../Helpers/Lst/lst.h"

typedef enum e_id
{
	a,
	b
} t_id;

typedef struct s_stack
{
	t_list		*lst;
	int			size;
	t_id		id;
} t_stack;

typedef struct s_stack_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
} t_stack_data;

void	stack_clear(t_stack *stack);

void	data_clear(t_stack_data data);

t_stack_data	data_ini();


#endif