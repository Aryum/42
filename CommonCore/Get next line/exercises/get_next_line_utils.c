/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:13:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/14 09:32:14 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	h_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (i);
}

int	h_appendbuffer(char **last, char *buffer)
{
	size_t	i;
	size_t	h;
	size_t	total_len;
	char	*retval;

	i = 0;
	h = h_strlen(buffer);
	total_len = h_strlen(*last) + h + (buffer[h] == '\n');
	retval = malloc(total_len + 1);
	if (retval == NULL)
		return (free(*last), 1);
	while ((*last) != NULL && (*last)[i] != '\0')
	{
		retval[i] = (*last)[i];
		i++;
	}
	h = 0;
	while (h + i < total_len)
	{
		retval[h + i] = buffer[h];
		h++;
	}
	retval[h + i] = '\0';
	free(*last);
	return (*last = retval, total_len != 0 && retval[h + i - 1] == '\n');
}

void	h_resetbuffer(char *buffer)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n' && buffer[i + 1] != '\0' && j == 0)
			j = i + 1;
		else if (j != 0)
			buffer[i - j] = buffer[i];
		i++;
	}
	if (j == 0)
		buffer[0] = '\0';
	buffer[i - j] = '\0';
}

ssize_t	h_readfile(int fd, char *buffer, ssize_t *readbytes)
{
	*readbytes = read(fd, buffer, BUFFER_SIZE);
	buffer[*readbytes] = '\0';
	return (*readbytes);
}
