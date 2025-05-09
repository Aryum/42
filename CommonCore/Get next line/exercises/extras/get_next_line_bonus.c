/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:41:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/09 14:37:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	static char buffer[FOPEN_MAX][BUFFERSIZE + 1];
	char 	*ret;
	size_t	readbytes;
	
	if (fd < 0 || fd > 15)
		return (NULL);
	ret = malloc(1);
	ret[0] = '\0';
	if(buffer[0] != '\n')
		h_appendstr(&ret,buffer[fd]);
	h_readfile(fd, buffer,&readbytes);
	while (readbytes > 0)
	{
		if(h_appendstr(&ret,buffer[fd]))
			break;
		h_readfile(fd, buffer,&readbytes);
	}
	h_resetbuffer(buffer[fd],readbytes);
	if(ret[0] == '\0')
		return (free(ret), NULL);
	return ret;
}

