#include "libft.h"
#include "test_tochr.h"
#include  <ctype.h>

int main(int argc, char ** agrv)
{
	tochr_logMessages(tolower, ft_tolower, argc != 1);
}
