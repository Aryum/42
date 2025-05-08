/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:36:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/08 09:56:51 by ricsanto         ###   ########.fr       */
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
	readbytes = read(fd, *buffer, BUFFERSIZE);
	while (readbytes > 0 && targetline != 0)
	{
		i = 0;
		if(currentline == targetline)
				return (0);
		while((*buffer)[i] != '\0')
		{
			if((*buffer)[i] == '\n')
			{
				currentline++;
				printf("found a new line at %d (%c)\n",i,(*buffer)[i] );
				if(currentline == targetline)
					return (i + 1);
			}
			i++;
		}
		readbytes = read(fd, *buffer, BUFFERSIZE);
	}
	return (0);
}

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

void	appendstr(int start, char **last, char *buffer)
{
	size_t	i;
	size_t	h;
	size_t	total_len;
	char	*retval;

	i = 0;
	h = get_strlen(buffer);
	total_len = get_strlen(*last) + h - start + (buffer[h] == '\n');
	//printf("total length %d\n", total_len);
	retval = malloc(total_len + 1);
	if (retval == NULL)
		return ;
	while ((*last) != NULL && (*last)[i] != '\0')
	{
		retval[i] = (*last)[i];
		i++;
	}
	h = 0;
	while (h + i < total_len)
	{
		retval[h + i] = buffer[h + start];
		h++;
	}
	retval[h + i] = '\0';
	free(*last);
	*last = retval;
}

char *get_line(int fd, char **buffer, int start)
{
	size_t readbytes;
	char *ret;
	int res;
		
	readbytes = 1;
	ret =  NULL;
	while (readbytes > 0)
	{
		appendstr(start,&ret, *buffer);
		//printf("char at retsize - 1 = (%c)\n", ret[get_strlen(ret)] );
		if(ret[get_strlen(ret)] == '\n' || ret == NULL)
			break;
		readbytes = read(fd, *buffer, BUFFERSIZE);
	}
	return (ret);
}

char *get_next_line(int fd)
{
	static int line = 0;
	char *buffer;
	int startindex;
	char *ret;
	
	buffer = malloc(BUFFERSIZE + 1);
	if(buffer == NULL)
		return (NULL);
	buffer[BUFFERSIZE] = '\0';
	startindex = get_startindex(fd, &buffer, line);
	printf("-------------------------\n");
	printf("%d line\n|%s|buffer\nstart at %d (%c)\n", line,buffer, startindex, buffer[startindex]);
	printf("-------------------------\n");
	ret = get_line(fd,&buffer,startindex);
	free(buffer);
	line ++;
	
	return (ret);
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
#include <fcntl.h>
int main()
{
	/*
	char *str1;
	char *str2;
	char *str3;
	
	str1 = strdup("hello");
	str2 = strdup(" i am working");
	str3 = strdup("not this is showing\nthis is not");

	appendstr(0,&str1, str2);
	printf("%s\n", str1);
	appendstr(3,&str1, str3);
	printf("%s\n", str1);
	free(str1);
	free(str2);
	free(str3);
	*/

	int fd =  open("test.txt",O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s\n",str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n",str);
	free(str);
	close(fd);
	
}