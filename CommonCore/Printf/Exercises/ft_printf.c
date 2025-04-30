/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 11:45:10 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	•%c Prints a single character.
	•%s Prints a string (as defined by the common C convention).
	•%p The void * pointer argument has to be printed in hexadecimal format.
	•%d Prints a decimal (base 10) number.
	•%i Prints an integer in base 10.
	•%u Prints an unsigned decimal (base 10) number.
	•%x Prints a number in hexadecimal (base 16) lowercase format.
	•%X Prints a number in hexadecimal (base 16) uppercase format.
	•%% Prints a percent sign.
*/

/*
	TO DO
	->test normal behaviour is the combination of flags and what they do
	->Function that converts param into string 
	->Function that applies the flags to resulting string
*/












int	ft_printf(int n, ...)
{
	/*
	va_list args;
	//check what protection it needs
	//->if str is just %
	//->if in the middle it just finds % without anything after
	



	va_start(args,n);

	va_end(args);
	*/
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
			if(str[i + 1] == 'p')
				write (1, "ptr", 4);
			if(str[i + 1] == 'd')
				write (1, "dec", 4); //convert a number in a base to decimal
			if(str[i + 1] == 'i')
				write (1,"int",1);
			if(str[i + 1] == 'u') 
				write (1, "uns", 4);
			if(str[i + 1] == 'x')
				write (1, "hex", 4);
			if(str[i + 1] == 'X')
				write (1, "HEX", 4);
			if(str[i + 1] == '%')
				write (1, "per", 4);
			
			i++;
		}
		i++;
	}
}


#include <stdio.h>
/*
	•%c Prints a single character.
	•%s Prints a string (as defined by the common C convention).
	•%p The void * pointer argument has to be printed in hexadecimal format.
	•%d Prints a decimal (base 10) number.
	•%i Prints an integer in base 10.
	•%u Prints an unsigned decimal (base 10) number.
	•%x Prints a number in hexadecimal (base 16) lowercase format.
	•%X Prints a number in hexadecimal (base 16) uppercase format.
	•%% Prints a percent sign.
*/

int main()
{
	int a = 1;
	//printf("Pointer adress int\n");
	//printf("%ls\n", &a);
	int d = 96;
	long ln = 9223372036854775807;
	int chr = 300;
	printf("\nString size %i\n",printf("char %c\nchar overflow val %c\nDecimal %d\nDecimal Ptr %d\nInt %i\nInt Ptr %d\nUnsigned + %u\nUnsigned - %u\nPointer at memory %p\nPointer at value %p\nhex positive %x\nhex negative %x\nhexadecimal on long %x\n", 
		d,chr,d, &d, d, &d, d, -d, &d, d, d, -d,ln));

	/*
		Decimal 10
		Decimal Ptr 1418255024
		Int 10
		Int Ptr 1418255024
		Unsigned + 10
		Unsigned - 4294967286
		Pointer at memory 0x7ffd5488dab0
		Pointer at value 0xa
		hex positive a
		hex negative fffffff6
		hexadecimal on long ffffffff
		
		String size 187



	conclusions
		%d and %i does the same thing
		%u is unsigned if it is positive it loops arround and subracts value
		%p just converts int value to hexadecimal with 0x at the beginning
		%x uses unsigned int to convert number it its a long just converts to max int

		7fff654702d0
		ffffffffffff
	*/

}