/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:33:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/04 16:36:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LST_H
# define LST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*last;
}	t_list;

t_list	*ft_lstnew(void *content);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstlast(t_list *lst);

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif