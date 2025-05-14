#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h>

void print(int fd, char **str)
{
	if(*str != NULL)
	{
		printf("fd%d -> %s",fd,*str);
		free(*str);
		*str = get_next_line(fd);
	}
}

int main()
{
	int fd1 =  open("main.c",O_RDONLY);
	int fd2 =  open("get_next_line_utils.c",O_RDONLY);

	char *str1 = get_next_line(fd1);
	char *str2 = get_next_line(fd2);
	while(str1 != NULL || str2 != NULL)
	{
		print(fd1,&str1);
		print(fd2,&str2);	
	}
}