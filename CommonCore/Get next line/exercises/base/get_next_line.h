/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:52:26 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/12 09:41:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

#include <unistd.h>
#include <stdlib.h>

void h_readfile(int fd,char *buffer,size_t *readbytes);

void h_resetbuffer(char *buffer);

int	h_appendstr(char **last, char *buffer);

char *get_next_line(int fd);

#endif