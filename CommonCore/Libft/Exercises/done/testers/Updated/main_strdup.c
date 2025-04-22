#include "libft.h"
#include "test_strdup.h"
#include  <ctype.h>
#include <string.h>

int main(int argc, char ** agrv)
{
	char *(*func[2])(const char *) = {strdup,ft_strdup};
	strdup_logMessages(func, argc != 1);
}
