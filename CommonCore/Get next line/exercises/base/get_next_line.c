/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:41:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/12 09:48:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 	*ret;
	size_t	readbytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0|| read(fd,0,0) < 0)
		return (NULL);
	ret = malloc(1);
	ret[0] = '\0';
	if(BUFFER_SIZE != 1)
		h_appendstr(&ret,buffer);
	h_readfile(fd, buffer,&readbytes);
	while (readbytes > 0)
	{
		if(h_appendstr(&ret,buffer))
			break;
		h_readfile(fd, buffer,&readbytes);
	}
	h_resetbuffer(buffer);
	if(ret[0] == '\0')
		return (free(ret), NULL);
	return ret;
}

