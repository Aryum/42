/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:05:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRT_H
# define SRT_H

# include "../Helpers/Lst/lst.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
} t_stacks;

int	print_f(const char *string, ...);

void	srt_h_print(char *str, char c);

//push
void srt_push_a(t_stacks *lsts);

void srt_push_b(t_stacks *lsts);

//rotate
void	srt_rotate_a(t_stacks *lsts);

void	srt_rotate_b(t_stacks *lsts);

void	srt_rotate_both(t_stacks *lsts);

//rev rotate
void	srt_rotate_rev_a(t_stacks *lsts);

void	srt_rotate_rev_b(t_stacks *lsts);

void	srt_rotate_rev_both(t_stacks *lsts);

//swap
void	srt_swap_a(t_stacks *lsts);

void	srt_swap_b(t_stacks *lsts);

void	srt_swap_both(t_stacks *lsts);

#endif