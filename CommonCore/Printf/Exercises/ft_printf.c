/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/01 15:25:18 by ricsanto         ###   ########.fr       */
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


#include "printf.h"


int ft_printf(const char *, ...)
{
/*
	probably should give errror if only one % is found and doesnt print anything
*/
	
	/*
	va_list args;
	//check what protection it needs
	//->if str is just %
	//->if in the middle it just finds % without anything after
	




	va_end(args);
	*/
}

/*
int test(int n, ...)
{
	int	counter;
	int i;
	char *str;
	
	va_list args;
	va_start(args, n);
	str = va_arg(args, char *);
	
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			if(str[i + 1] == 'c')
				h_put_char(va_arg(args, int),&counter);
			if(str[i + 1] == 's')
				h_put_str(va_arg(args, char *),&counter);
			if(str[i + 1] == 'p')
				h_put_ptr(va_arg(args, void *),&counter);
			if(str[i + 1] == 'd' || str[i + 1] == 'i')
				h_put_int(va_arg(args, int),&counter);
			if(str[i + 1] == 'u') 
				h_put_uint(va_arg(args, unsigned int),&counter);
			if(str[i + 1] == 'x')
				h_print_nbrbase(va_arg(args, unsigned int),"0123456789abcdef",&counter);
			if(str[i + 1] == 'X')
				h_print_nbrbase(va_arg(args, unsigned int),"0123456789ABCDEF",&counter);
			if(str[i + 1] == '%')
				h_put_char('%',&counter);
			i++;
		}
		i++;
	}
	va_end(args);
	return counter;
}

*/
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
	
	char *str1 ="\nString size %i\n\n";
	char *str2 ="char %c\nchar overflow val %c\nDecimal %d\nDecimal Ptr %d\nInt %i\nInt Ptr %d\nUnsigned + %u\nUnsigned - %u\nPointer at memory %p\nPointer at value %p\nhex positive %x\nhex negative %x\nhexadecimal on long %x\n";
	
	char *str3 = "\nString size of just %% %i\n\n";
	char *str4 ="%";
	
	char *str5 ="\nString size of %% and more %i\n\n";
	char *str6 ="% I have more\n";
	
	char *str7 ="\nString size of %% with param %i\n\n";
	char *str8 ="% I have more and a valid int %d\n";
	
	char *str9 ="\nString size of %% with spaces between %i\n\n";
	char *str10 ="%    i hello am i working\n";

	char *str11 ="\nString size of %% with whitespaces between %i\n\n";
	char *str12 ="% \n   \n";
	
	char *str13 ="\nString size of %% with whitespaces between  and more %i\n\n";
	char *str14 ="% \ni hello am i working\n";
	
	printf(str1,printf(str2, d,chr,d, &d, d, &d, d, -d, &d, d, d, -d,ln));
	printf("-------------------------------------------------------------------\n");
	printf(str3, printf(str4));
	printf("-------------------------------------------------------------------\n");
	printf(str5, printf(str6));
	printf("-------------------------------------------------------------------\n");
	printf(str7, printf(str8,d));
	printf("-------------------------------------------------------------------\n");
	printf(str9, printf(str10,d));
	printf("-------------------------------------------------------------------\n");
	printf(str11, printf(str12,d));
	printf("-------------------------------------------------------------------\n");
	printf(str13, printf(str14,d));
	printf("-------------------------------------------------------------------\n");
	printf("\n\n\n");
	
	//test(str1,test(str2, d,chr,d, &d, d, &d, d, -d, &d, d, d, -d,ln));

	/*
		char `
		char overflow val ,
		Decimal 96
		Decimal Ptr 726993012
		Int 96
		Int Ptr 726993012
		Unsigned + 96
		Unsigned - 4294967200
		Pointer at memory 0x7ffe2b550874
		Pointer at value 0x60
		hex positive 60
		hex negative ffffffa0
		hexadecimal on long ffffffff

		String size 243

		-------------------------------------------------------------------

		String size of just % -1

		-------------------------------------------------------------------
		0x0.07ffe2b55081p-1022ve more

		String size of % and more 31

		-------------------------------------------------------------------
		0x0.07ffe2b55081p-1022ve more and a valid int 96

		String size of % with param 50

		-------------------------------------------------------------------
		96 hello am i working

		String size of % with spaces between 23

		-------------------------------------------------------------------
		% 
		

		String size of % with whitespaces between 7

		-------------------------------------------------------------------
		% 
		i hello am i working

		String size of % with whitespaces between  and more 24

		-------------------------------------------------------------------




	conclusions
		%d and %i does the same thing
		%u is unsigned if it is positive it loops arround and subracts value
		%p just converts int value to hexadecimal with 0x at the beginning
		%x uses unsigned int to convert number it its a long just converts to max int

		7fff654702d0
		ffffffffffff
	*/

}