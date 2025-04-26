#include "libft.h"
#include "test_tochr.h"
#include  <ctype.h>

int main(int argc, char ** agrv)
{
	tochr_logMessages(toupper,ft_toupper, argc != 1);
}
