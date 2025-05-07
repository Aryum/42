/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:36:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/07 11:12:50 by ricsanto         ###   ########.fr       */
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
	
	currentline = 0;
	readbytes = 1;
	while (readbytes > 0)
	{
		readbytes = read(fd, *buffer, BUFFERSIZE);
		i = 0;
		while((*buffer)[i] != '\0')
		{
			if(currentline == targetline)
				return (i);
			if((*buffer)[i] == '\n')
				currentline++;
			i++;
		}
	}
	return (-1);
}

size_t get_strlen(char *str)
{
	size_t i;

	i = 0;
	if(str != NULL)
	{
		while(str[i] != '\0')
			i++;
	}
	return (i);
}

int	cleanstr(char **str)
{
	char *temp;
	size_t	len;
	int	i;
	int h;
	
	i = 0;
	len = get_strlen(*str);
	while ((*str)[len - i - 1] != '\n' && i < len)
		i++;
	if ((*str)[len - i - 1] != '\n')
		return (0);
	temp = malloc(len - i + 1);
	if(temp == NULL)
		return (-1);
	i = 0;
	while((*str)[i] != '\n')
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[i] = '\n';
	temp[i + 1] = '\0';
	free(*str);
	*str = temp;
	return (1);
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
		res = cleanstr(ret);
		if(res != 0)
		{
			if(es)
			break;
		}
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
	printf("start index %d (%c)\n", startindex, buffer[startindex]);
	//ret = get_line(fd,&buffer,startindex);
	line ++;
	return (NULL);
}

#include <fcntl.h>
int main()
{
	/**/
	int fd =  open("test.txt",O_RDONLY);
	char *str = get_next_line(fd);
	str = get_next_line(fd);
	printf("%s\n", str);

	free(str);
}