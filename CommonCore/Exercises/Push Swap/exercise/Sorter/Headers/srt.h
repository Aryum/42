/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 13:11:51 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRT_H
# define SRT_H

# include "lst.h"

int	print_f(const char *string, ...);

int	srt_h_is_lstnull(t_list **lst);

int	srt_h_is_first(t_list **lst);

void	srt_h_print(char *str);

#endif