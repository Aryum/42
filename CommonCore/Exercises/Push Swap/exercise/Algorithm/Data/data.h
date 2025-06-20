/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:11:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/20 13:07:29 by ricsanto         ###   ########.fr       */
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
	t_list	*lst;
	t_id	id;
	int		size;
	int		max;
	int		min;
} t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
} t_data;

typedef struct s_func
{
	void (*push)(t_data);
	void (*rot)(t_data);
	void (*rev_rot)(t_data);
	void (*swap)(t_data);
} t_func;

# include "../_Headers/alg.h"

void	stack_clear(t_stack *stack);

void	data_clear(t_data data);

t_data		data_ini();

t_stack		*get_stack(t_data stack, t_id id);

t_func		get_func(t_id id);

t_list		*get_lst_topush(t_data data, t_id pushto);

#endif