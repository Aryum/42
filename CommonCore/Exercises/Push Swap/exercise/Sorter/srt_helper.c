/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:48:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 13:12:10 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/srt.h"

int	srt_h_is_lstnull(t_list **lst)
{
	return (lst == NULL && *lst == NULL);
}

int	srt_h_is_first(t_list **lst)
{
	return (lst == NULL || *lst == NULL || (*lst)->last == NULL);
}
void	srt_h_print(char *str)
{
	print_f("%s\n", str);
}