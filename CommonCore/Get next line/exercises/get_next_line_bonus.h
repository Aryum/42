/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:58:57 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/12 20:39:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		h_appendstr(char **last, char *buffer);

char	*get_next_line(int fd);

void	h_resetbuffer(char *buffer);

ssize_t	h_readfile(int fd, char *buffer, ssize_t *readbytes);

#endif
