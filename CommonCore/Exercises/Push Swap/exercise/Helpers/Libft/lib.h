/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 14:30:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef lib
# define lib

#include <stdlib.h>

void	lib_bzero(void *s, size_t n);

void	*lib_calloc(size_t nmemb, size_t size);

void	*lib_memset(void *s, int c, size_t n);

char	**lib_split(char const *s, char c);

void	lib_split_clean(char **arr, size_t lastindex);

char	*lib_substr(char const *s, unsigned int start, size_t len);

size_t	lib_strlen(const char *s);

size_t	lib_strlcpy(char *dst, const char *src, size_t size);

char	*lib_strdup(const char *s);

#endif