/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:11:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:09:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../../Helpers/Lst/lst.h"
# include "../_Headers/alg.h"

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

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
} t_data;

typedef struct s_functions
{
	void (*rotate)(t_data);
	void (*rev_rotate)(t_data);
	void (*push)(t_data);
	void (*swap)(t_data);
} t_functions;



void	stack_clear(t_stack *stack);

void	data_clear(t_data data);

#endif