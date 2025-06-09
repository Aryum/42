/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:33:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 15:23:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*last;
}	t_list;

t_list	*lst_new(int content);

t_list	*lst_map(t_list *lst, int (*f)(int));

t_list	*lst_last(t_list *lst);

void	lst_iter(t_list *lst, void (*f)(int));

void	lst_delone(t_list **start, t_list *node);

void	lst_add_back(t_list **lst, int new);

void	lst_add_front(t_list **lst, int new);

void	lst_clear(t_list **lst);

#endif