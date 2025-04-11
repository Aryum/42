#include <stdio.h>
#include <ctype.h>
#include "tests.h"

int ft_isalpha(int i);

int main(int agrc, char **argv)
{
	logMessages(isalpha, ft_isalpha, agrc != 1);
	return 0;
}