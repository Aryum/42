#include <stdio.h>
#include <ctype.h>
#include "tests.h"

int ft_isdigit(int i);

t_tests createTestParams (int a, int b, char *name)
{
	return createTestParams_BASE(a,b,name, isdigit);
}

int main()
{
	t_tests tests[] = 
	{ 	createTestParams('A', 'Z', "Upper case"), 
		createTestParams('a', 'z', "Lower case"), 
		createTestParams(0, 'A'-1, "Simbols and numbers pt1"),
		createTestParams('Z'+1, 'a'-1, "Simbols and numbers pt2"), 
		createTestParams('z'+1, 127, "Simbols and numbers pt3"),
		createTestParams(-128, 0, "Negative chars"),
		createTestParams(255, 300, "Out of range value"),
		createTestParams(0, 0, (void *)0),

	};
	logMessages(tests, ft_isdigit);
}