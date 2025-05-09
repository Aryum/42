/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:55:11 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/09 09:02:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h>

size_t get_strlen(char *str)
{
	size_t i;

	i = 0;
	if(str != NULL)
	{
		while(str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (i);
}

int	appendstr(char **last, char *buffer)
{
	size_t	i;
	size_t	h;
	size_t	total_len;
	char	*retval;

	i = 0;
	h = get_strlen(buffer);
	total_len = get_strlen(*last) + h + (buffer[h] == '\n');
	retval = malloc(total_len + 1);
	if (retval == NULL)
		return (1);
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
	return (*last = retval, retval[h + i - 1] == '\n');
}

void resetbuffer(char *buffer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if(buffer[i] == '\n' && buffer[i + 1] != '\0' && j == 0)
			j = i + 1;
		else if(j != 0)
			buffer[i - j] = buffer[i];
		i++;
	}
	buffer[i - j] = '\0';
}


//make it work with 1 read size
//if readsize is 1 and 
char *get_next_line(int fd)
{
	static char buffer[BUFFERSIZE +1];
	size_t readbytes;
	char *ret;
	int start;
	
	buffer[BUFFERSIZE] = '\0';
	ret = malloc(1);
	ret[0] = '\0';
	if(buffer[0] != '\n' && appendstr(&ret,buffer))
		ret;
	readbytes = read(fd, buffer, BUFFERSIZE);
	while (readbytes > 0)
	{
		appendstr(&ret,buffer);
		if(ret[get_strlen(ret)] == '\n' || ret == NULL)
			break;
		readbytes = read(fd, buffer, BUFFERSIZE);
	}
	resetbuffer(buffer);
	printf("ret |%s|\n\n",ret);
	return ret;
}
char *strdup(char *str)
{
	char * ret;
	int i;

	i= 0;
	while(str[i] != '\0')
		i++;
	ret = malloc(i + 1);
	i = 0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = str[i];
	return ret;
}

int main()
{
	/*
	int fd =  open("test.txt",O_RDONLY);
	char *str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	*/

	static char test[BUFFERSIZE+1];
	test[BUFFERSIZE] = '\0';
	
	int i = 0;
	while(i < BUFFERSIZE)
	{
		printf("is null terminated? %s", test[i] == '\n')
		if();
	}
}