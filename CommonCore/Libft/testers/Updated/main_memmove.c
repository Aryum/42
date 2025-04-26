#include "libft.h"
#include "test_memmove.h"
#include  <ctype.h>
#include <string.h>

int main(int argc, char ** agrv)
{
	void*(*funcs[2])(void *, const void *, size_t ) = {memmove,ft_memmove};
	memmove_logMessages(funcs, argc != 1);
}
