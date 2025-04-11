/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:02:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/11 15:32:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include<string.h>


int ft_isalpha(int i);

int ft_isdigit(int c);

int ft_isalnum(int c);

int	ft_isascii(int c);

int ft_isprint(int c);

size_t ft_strlen(const char *s);

void *ft_memset(void *s, int c, size_t n);
#endif

