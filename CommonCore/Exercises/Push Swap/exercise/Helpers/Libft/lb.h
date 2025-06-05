/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:30:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LB
# define LB

#include <stdlib.h>

void	lb_bzero(void *s, size_t n);

void	*lb_calloc(size_t nmemb, size_t size);

void	*lb_memset(void *s, int c, size_t n);

char	**lb_split(char const *s, char c);

char	*lb_substr(char const *s, unsigned int start, size_t len);

size_t	lb_strlen(const char *s);

size_t	lb_strlcpy(char *dst, const char *src, size_t size);

char	*lb_strdup(const char *s);

#endif