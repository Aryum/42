#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h>

void print(int fd)
{
	char *str = get_next_line(fd);
	printf("ret |%s|\n\n",str);
	if(str != NULL)
		free(str);
}

int main()
{
	int fd =  open("test.txt",O_RDONLY);
	print( fd);
	print( fd);
	print( fd);
	print( fd);
	print( fd);
	print( fd);
	print( fd);
}