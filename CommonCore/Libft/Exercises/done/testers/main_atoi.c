#include "test_atoi.h"
#include <stdlib.h>
#include "libft.h"

int main(int argc, char ** agrv)
{
	int(*func[2])(const char *) = {atoi, ft_atoi};
	atoi_logMessages(func, argc != 1);
}