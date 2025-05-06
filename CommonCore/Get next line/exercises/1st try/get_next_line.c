/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:36:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/06 18:36:41 by ricsanto         ###   ########.fr       */
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
	
	i = 0;
	currentline = 0;
	readbytes = 1;
	while (readbytes > 0)
	{
		readbytes = read(fd, *buffer, BUFFERSIZE);
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

int get_strlen(char *str)
{
	int i;

	i = 0;
	if(str != NULL)
	{
		while(str[i] != '\0')
			i++;
	}
	return (i);
}

void	cleanbuffer(char **buffer)
{
	char *temp;
	int	len;
	int	i;
	int h;
	
	i = 0;
	len = get_strlen(*buffer);
	while ((*buffer)[len - i - 1] != '\n' && i < len)
		i++;
	if ((*buffer)[len - i - 1] != '\n')
		return ;
	temp = malloc(len - i + 1);
	if(temp != NULL)
	{
		i = 0;
		while((*buffer)[i] != '\n')
		{
			temp[i] = (*buffer)[i];
			i++;
		}
		temp[i] = '\n';
		temp[i + 1] = '\0';
	}
	free(*buffer);
	*buffer = temp;
}



void appendstr(int start, char **last, char* buffer)
{
	char	*temp;
	int		i;
	int		total_len;

	i = 0;
	total_len = get_strlen(*last) + get_strlen(buffer) - start + 1;
	temp = malloc(total_len);
	if(temp == NULL)
		return ;
	while (*last != NULL && (*last)[i] !=  '\0')
	{
		temp[i] = (*last)[i];
		i++;
	}
	while (i + start < total_len - 1)
	{
		temp[i + start] = buffer[start];
		start++;
	}
	temp[i + start] = buffer[start];
	free(*last);
	*last = temp;
}


char *get_line(int fd, char **buffer, int start)
{
	int readbytes;
	char *ret;
	
	readbytes = 1;
	ret =  NULL;
	while (readbytes > 0 && start != -1)
	{
		readbytes = read(fd, *buffer, BUFFERSIZE);
		cleanbuffer(buffer);
		if(buffer == NULL)
			break ;
		appendstr(start,&ret, *buffer);
		if(ret == NULL)
			break;
		start = 0;
		if (ret[get_strlen(ret) - 1] == '\n')
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
	ret = get_line(fd,&buffer,startindex);
	if (ret != NULL)
		line ++;
	return (ret);
}

#include <fcntl.h>
int main()
{
	char *str = NULL;
	char *str1 = "Hello";
	char *str2 = " World";
	char *str3 = "wa I am working";
	
	appendstr(0,&str,str1);
	printf("%s\n", str);
	appendstr(0,&str,str2);
	printf("%s\n", str);
	appendstr(2,&str,str3);
	printf("%s\n", str);

	free(str);
}