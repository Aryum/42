/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:52:26 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/09 14:26:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFERSIZE
# define BUFFERSIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	h_appendstr(char **last, char *buffer);

int	h_appendstr(char **last, char *buffer);

void h_resetbuffer(char *buffer, size_t readbytes);

char *get_next_line(int fd);


#endif