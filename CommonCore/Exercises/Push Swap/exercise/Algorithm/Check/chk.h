/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/23 17:20:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHK_H
# define CHK_H

# include "../_Headers/alg.h"

typedef enum e_dir
{
	reverse,
	normal,
	none
} t_dir;

typedef struct s_sequence
{
	t_dir	dir;
	int		start;
	int		end;

} t_sequence;

int	next_lower(t_list *lst);

int	next_bigger(t_list *lst);

int	is_sorted(t_stack stack);

int	is_rev_sorted(t_stack stack);

int	is_max_onbottom(t_stack stack);

int	is_max_ontop(t_stack stack);

int	is_min_ontop(t_stack stack);

int	is_min_onbottom(t_stack stack);

int	is_uprchunk(t_chunk chunk, int i);

//int	has_sequence(t_stack stack, t_sequence *seq);

#endif