#include "h_parser.c"
#include <stdio.h>

void printStr(char *c)
{
	long nbr = 0;
	if(is_validnumber(c, &nbr))
		printf("%s = %ld\n",c,nbr);
	else
		printf("%s is an invalid input\n", c);
}
int main()
{
	printStr("01234");
	printStr("01a234");
	printStr("-01a234");
	printStr("-01234a");
	printStr("-01234");
	printStr("-85476");
	printStr("-abes");
	printStr("-");
	printStr("-2147483648");
	printStr("2147483647");
	printStr("2147483649");
	printStr("10456147483649");

	printStr("2147483649adswsw");
	printStr("2147483649adswsw");
	printStr("92233720368547755454809");



	
}