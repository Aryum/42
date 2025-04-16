#include "libft.h"
#include "test_strnstr.h"
#include  <ctype.h>
#include <bsd/string.h>
#include <string.h>


int main(int argc, char ** agrv)
{
	char *(*func[2])(const char *) = {strnstr,ft_strnstr};
	strnstr_logMessages(func, argc != 1);
}
