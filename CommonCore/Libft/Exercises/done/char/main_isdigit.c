#include "libft.h"
#include <ctype.h>
#include "tests_char.h"

int main(int agrc, char **argv)
{
	char_logMessages(isdigit, ft_isdigit, agrc != 1);
	return 0;
}