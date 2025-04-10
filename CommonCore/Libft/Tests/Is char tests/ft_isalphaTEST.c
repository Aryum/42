#include <stdio.h>
#include <ctype.h>
#include "tests.h"

int ft_isalpha(int i);

t_tests createTestParams (int a, int b, char *name)
{
	return createTestParams_BASE(a,b,name, isalpha);
}

int main()
{
	logMessages(ft_isalpha);
	return 0;
}