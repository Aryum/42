/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:41:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/09 14:10:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFERSIZE +1];
	char 	*ret;
	size_t	readbytes;
	
	if (fd < 0)
		return (NULL);
	ret = malloc(1);
	ret[0] = '\0';
	if(buffer[0] != '\n')
		h_appendstr(&ret,buffer);
	h_readfile(fd, buffer,&readbytes);
	while (readbytes > 0)
	{
		if(h_appendstr(&ret,buffer))
			break;
		h_readfile(fd, buffer,&readbytes);
	}
	h_resetbuffer(buffer,readbytes);
	if(ret[0] == '\0')
		return (free(ret), NULL);
	return ret;
}

