/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:37:49 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 15:07:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

static t_sequence ini()
{
	t_sequence	ret;

	ret.dir = none;
	ret.start = -1;
	ret.end = -1;
	return (ret);
}

static void lookforend(t_list *lst, t_sequence *sq, int (*chk)(t_list *))
{
	sq->start = lst->val.index;
	while (lst->next !=  NULL)
	{
		if (!chk(lst))
		{
			sq->end = lst->val.index;
			break ;
		}
		lst = lst->next;
	}
}

int	has_sequence(t_stack stack, t_sequence *seq)
{
	t_list		*lst;

	lst = stack.lst;
	*seq = ini();
	while (lst->next !=  NULL)
	{
		if (next_bigger(lst))
		{
			seq->dir = normal;
			lookforend(lst, seq, next_bigger);
			break ;
		}
		else if (next_lower(lst))
		{
			seq->dir = reverse;
			lookforend(lst, seq, next_lower);
			break ;
		}
		lst = lst->next;
	}
	return (seq->dir != none);
}
