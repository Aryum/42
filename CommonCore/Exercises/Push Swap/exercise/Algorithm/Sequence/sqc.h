/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 14:00:55 by ricsanto         ###   ########.fr       */
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

int	is_sorted(t_stack stack);

int	is_rev_sorted(t_stack stack);
#endif