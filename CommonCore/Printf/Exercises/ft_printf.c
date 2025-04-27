/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/27 16:22:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prtf.h"

/*
	%c char
	%s string 
	%d decimal
	%i int base 10
	%u unsigned int
	%x hexadecimal minusculas
	%X hexadecimal maiusculas
	%% per cent sign
	
	BONUS
	-      Left justify.
   	0  	  Field is padded with 0's instead of blanks.
   	+	  Sign of number always O/P.
	(value).(value) minimum width and max width
    blank  Positive values begin with a blank.
    # 	  Various uses:
	  %#x (Hex)   0x prefix added to non-zero values.
	  %#X (Hex)   0X prefix added to non-zero values.

	//must all work together
	'-0.'
	//only one of them
	'# +'
*/

/*
	TO DO
	->test normal behaviour is the combination of flags and what they do
	->Function that finds flags and checks if they are correct
	->Function that converts param into string 
	->Function that applies the flags to resulting string
*/


char *create_char(char c)
{}
char *create_string(char *s)
{}
char *print_decimal(int i)
{}
char *print_base( char *flags)
{}
char *print_unsigned(unsigned int i)
{}
//just use to upper to print %X
char *print_hex(int i)
{}
int	ft_printf(int n, ...)
{
	va_list args;
	
	va_start(args,n);

	//go through string
	//print until it finds %-
	//when it finds check which one is it
	//print the arg
	//skip %- char
	//print repeat until profit
	va_end(args);
}


void test(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			if(str[i + 1] == 'c')
				write (1, "chr", 4);
			if(str[i + 1] == 's')
				write (1, "str", 4);
			if(str[i + 1] == 'd')
				write (1, "dec", 4); //convert a number in a base to decimal
			if(str[i + 1] == 'x')
				write (1, "hex", 4);
			if(str[i + 1] == 'X')
				write (1, "HEX", 4);
			if(str[i + 1] == 'u') 
				write (1, "uns", 4);
			if(str[i + 1] == '%')
				write (1, "per", 4);
			i++;
		}
		i++;
	}
}

int main()
{
	test("Char (%c)\nStr (%s)\nDec (%d)\nhex (%x)\nHEX (%X)\nUnsigned (%u)\nPer (%%) ");
}
/*



*/