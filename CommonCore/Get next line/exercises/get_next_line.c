/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:55:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/12 19:10:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	ssize_t readbytes;
	char *ret;

	if (fd < 0 || BUFFER_SIZE <= 0|| read(fd,0,0) < 0)
		return (NULL);
	ret = malloc(1);
	ret[0] = '\0';
	if(!h_appendstr(&ret,buffer))
	{
		while(h_readfile(fd,buffer,&readbytes) > 0)
		{
			if(h_appendstr(&ret,buffer) || readbytes < BUFFER_SIZE)
				break ;
		}
		if(readbytes < 0)
				return (free(ret), NULL);
	}
	if(ret[0] == '\0' && readbytes == 0)
		return (free(ret), NULL);
	else
		return (h_resetbuffer(buffer), ret);
}
/*
char *strdup(char *str)
{
	char * ret;

	int i = 0;
	while(str[i] != '\0')
		i++;
	ret = malloc (i + 1);
	i = 0;
	while(str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = str[i];
	return ret;
}
int main()
{
	char *test = strdup("Hello\nI am here\ntest");
	char *f = test;

	printf("|%s|\n",test);
	h_resetbuffer(test);
	printf("|%s|\n",test);
	h_resetbuffer(test);
	printf("|%s|\n",test);
	h_resetbuffer(test);
	printf("|%s|\n",test);
	h_resetbuffer(test);
	printf("|%s|\n",test);

	free(f);
	return 0;
}
*/
