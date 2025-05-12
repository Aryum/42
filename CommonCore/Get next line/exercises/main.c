#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h>

void print(int fd)
{
	
}

int main()
{
	int fd =  open("test copy.txt",O_RDONLY);

	char *str = get_next_line(fd);
	while(str != NULL)
	{
		printf("%s",str);
		free(str);
		str = get_next_line(fd);
	}
}