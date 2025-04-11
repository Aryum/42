#include <stdio.h>
#include <ctype.h>
#include "tests.h"

int ft_isdigit(int i);

int main(int agrc, char **argv)
{
	logMessages(isdigit, ft_isdigit, agrc != 1);
	return 0;
}