/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:55:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/14 10:23:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		readbytes;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	ret = malloc(1);
	ret[0] = '\0';
	if (!h_appendbuffer(&ret, buffer))
	{
		while (h_readfile(fd, buffer, &readbytes) > 0)
		{
			if (h_appendbuffer(&ret, buffer) || readbytes < BUFFER_SIZE)
				break ;
		}
	}
	if (ret[0] == '\0')
		return (free(ret), NULL);
	else
		return (h_resetbuffer(buffer), ret);
}
