#include <ctype.h>
#include "tests_char.h"

int main(int agrc, char **argv)
{
	char_logMessages(isalpha, ft_isalpha, agrc != 1);
	return 0;
}