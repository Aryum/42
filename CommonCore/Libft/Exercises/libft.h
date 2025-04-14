/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:02:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/14 11:00:41 by ricsanto         ###   ########.fr       */
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

int ft_toupper(int c);

int ft_tolower(int c);

size_t ft_strlen(const char *s);

void *ft_memset(void *s, int c, size_t n);

void ft_bzero(void *s, size_t n);

int ft_strncmp(const char *s1, const char *s2, size_t n);

int ft_memcmp(const void *s1, const void *s2, size_t n);

void *ft_memchr(const void *s, int c, size_t n);

char *ft_strchr(const char *s, int c);

char *ft_strrchr(const char *s, int c);

#endif

