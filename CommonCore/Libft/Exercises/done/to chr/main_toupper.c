#include "libft.h"
#include "test_tochr.h"
#include  <ctype.h>

int main(int argc, char ** agrv)
{
	tochr_logMessages(ft_toupper,toupper, argc != 1);
}
