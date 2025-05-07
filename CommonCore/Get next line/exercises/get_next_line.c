/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:36:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/07 13:33:08 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//1st
//	find target line
//2nd
//	at atarget line find the ammount to alloc
//3rd
//	allo and return desired string and increase line
//when it finds a new line 


//end index is i

//creates string

int	get_startindex(int fd, char **buffer, int targetline)
{
	int readbytes;
	int i;
	int currentline;
	
	currentline = 1;
	readbytes = 1;
	while (readbytes > 0)
	{
		readbytes = read(fd, *buffer, BUFFERSIZE);
		i = 0;
		if(currentline > targetline || readbytes == 0)
			break ;
		while((*buffer)[i] != '\0')
		{
			if((*buffer)[i] == '\n')
				currentline++;
			i++;
		}
	}
	return (i);
}

size_t get_strlen(char *str)
{
	size_t i;

	i = 0;
	if(str != NULL)
	{
		while(str[i] != '\0' || str[i] != '\n')
			i++;
	}
	return (i);
}

void	strjoin(char **last, char const *buffer)
{
	size_t	i;
	size_t	h;
	int		correction;
	char	*retval;

	i = 0;
	h = ft_strlen(buffer);
	retval = malloc(ft_strlen(*last) + h + 1 + (buffer[h - 1] == '\n'));
	if (retval != NULL)
		return ;
	while ((*last)[i] != '\0')
	{
		retval[i] = (*last)[i];
		i++;
	}
	h = 0;
	while (buffer[h] != '\0' && buffer[h] != '\n')
	{
		retval[h + i] = buffer[h];
		i++;
	}
	retval[h + i + 1] = '\0';
	free(*last);
	*last = retval;
}
void appendstr(int start, char **last, char* buffer)
{
	char	*temp;
	int		i;
	int		h;
	size_t	total_len;

	i = 0;
	h = 0;
	total_len = get_strlen(*last) + get_strlen(buffer) - start + 1;
	temp = malloc(total_len);
	if(temp == NULL)
		return ;
	while (*last != NULL && (*last)[i] !=  '\0')
	{
		temp[i] = (*last)[i];
		i++;
	}
	while (i + h < total_len - 1)
	{
		temp[i + h] = buffer[start + h];
		h++;
	}
	temp[i + start] = buffer[start];
	free(*last);
	*last = temp;
}


char *get_line(int fd, char **buffer, int start)
{
	size_t readbytes;
	char *ret;
	int	finalstr;
	int res;
		
	readbytes = 1;
	ret =  NULL;
	while (readbytes > 0 && start != -1)
	{
		readbytes = read(fd, *buffer, BUFFERSIZE);
		appendstr(start,&ret, *buffer);
		if(res != 0)
			break;
		if (finalstr)
			break ;
	}
	if (buffer != NULL)
		free(*buffer);
	return (ret);
}

char *get_next_line(int fd)
{
	static int line;
	char *buffer;
	int startindex;
	char *ret;
	
	buffer = malloc(BUFFERSIZE + 1);
	buffer[BUFFERSIZE] = '\0';
	startindex = get_startindex(fd, &buffer, line);
	printf("target line %d\n	start index %d (%c)\n", line,startindex, buffer[startindex]);
	//ret = get_line(fd,&buffer,startindex);
	line ++;
	return (NULL);
}

char *strdup(char *str)
{
	char * ret;
	int i;

	i= 0;
	ret = malloc(get_strlen(str) + 1);
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = str[i];
	return ret;
}
#include <fcntl.h>
int main()
{
	int fd = open("test.txt",O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}