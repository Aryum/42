/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/20 17:19:31 by ricsanto         ###   ########.fr       */
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

int	is_inchunk(int i, t_chunk chunk);

//int	has_sequence(t_stack stack, t_sequence *seq);

#endif