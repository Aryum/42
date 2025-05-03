/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/03 13:23:42 by ricsanto         ###   ########.fr       */
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


static formatstr(char c,va_list args, int *counter)
{
	if(c == 'c')
		h_put_char(va_arg(args, int),&counter);
	if(c == 's')
		h_put_str(va_arg(args, char *),&counter);
	if(c == 'p')
		h_put_ptr(va_arg(args, void *),&counter);
	if(c == 'd' || c == 'i')
		h_put_int(va_arg(args, int),&counter);
	if(c == 'u') 
		h_put_uint(va_arg(args, unsigned int),&counter);
	if(c == 'x')
		h_print_nbrbase(va_arg(args, unsigned int),"0123456789abcdef",&counter);
	if(c == 'X')
		h_print_nbrbase(va_arg(args, unsigned int),"0123456789ABCDEF",&counter);
	if(c == '%')
		h_put_char('%',&counter);
}
int ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	args;
	
	if(str == NULL)
		return (-1);
	ret = 0;
	i = 0;
	if (ret != -1)
	{
		va_start(args, h_count_args(str));
		while (str[i] != '\0')
		{
			if (str[i] != '\0')
				h_put_char(str[i], ret);
			else
			{
				formatstr(str[i + 1], args, ret);
				i++;
			}
			i++;
		}
		va_end(args);
	}
	return (ret);
	/*
	probably should give errror if only one % is found and doesnt print anything
*/
/*
	int		ret;
	//check what protection it needs
	//->if str is just %
	//->if in the middle it just finds % without anything after
	ret = h_count




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
	str = va_arg(args, char *);
	
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			
			i++;
		}
		i++;
	}
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

int printtest(int *counter, char *str)
{
	(*counter)++;
	printf("___________________________________________________________________\n");
	printf("Test %d - %s\n", *counter, str == NULL ? "" : str);
	printf("-------------------------------------------------------------------\n");
}
int main()
{
	int counter = 0;
	int a = 1;
	//printf("Pointer adress int\n");
	//printf("%ls\n", &a);
	int d = 96;
	long ln = 9223372036854775807;
	int chr = 300;
	char *nul = NULL;
	
	
	
	//undefined behaviour
	
	char *str1 ="\nString size %i\n\n";
	char *str2 ="char %c\nchar overflow val %c\nDecimal %d\nDecimal Ptr %d\nInt %i\nInt Ptr %d\nUnsigned + %u\nUnsigned - %u\nPointer at memory %p\nPointer at value %p\nhex positive %x\nhex negative %x\nhexadecimal on long %x\n";
	printtest(&counter, NULL);
	printf(str1,printf(str2, d,chr,d, &d, d, &d, d, -d, &d, d, d, -d,ln));

	
	char *str3 = "\nString size of just %% %i\n\n";
	char *str4 ="%";
	printtest(&counter, NULL);
	printf(str3, printf(str4));


	char *str5 ="\nString size of %% and more %i\n\n";
	char *str6 ="%   have more\n";
	printtest(&counter, "Undefined");
	printf(str5, printf(str6));


	char *str7 ="\nString size of %% with param %i\n\n";
	char *str8 ="%    gwa have more and a valid int %d\n";
	printtest(&counter, "Undefined");
	printf(str7, printf(str8,d));


	char *str9 ="\nString size of %% with spaces between %i\n\n";
	char *str10 ="%    i hello am i working\n";
	printtest(&counter, NULL);
	printf(str9, printf(str10,d));

	char *str11 ="\nString size of %% with whitespaces between %i\n\n";
	char *str12 ="%\n   \n";
	printtest(&counter, NULL);
	printf(str11, printf(str12,d));


	char *str13 ="\nString size of %% with whitespaces between  and more %i\n\n";
	char *str14 ="% \ni hello am i working\n";
	printtest(&counter, NULL);
	printf(str13, printf(str14,d));



	char *str15 ="\nString size of null string %i\n\n";
	char *str16 ="%s\n";
	printtest(&counter, NULL);
	printf(str15, printf(str16,nul));



	char *str17 ="\nString size of null ptr %i\n\n";
	char *str18 ="%p\n";
	printtest(&counter, NULL);	
	printf(str17, printf(str18,nul));


	char *str19 ="\nString size of null not inicialiazed ptr %i\n\n";
	char *str20 ="%p\n";
	printtest(&counter, NULL);	
	printf(str19, printf(str20,nul));


	char *str21 ="\nString size of null input string %i\n\n";
	char *str22 = NULL;
	printtest(&counter, NULL);	
	printf(str21, printf(str22,nul));
	printf("___________________________________________________________________\n");

	printf("\n\n\n");
	
	//test(str1,test(str2, d,chr,d, &d, d, &d, d, -d, &d, d, d, -d,ln));

	/*
		___________________________________________________________________$
		Test 1 - $
		-------------------------------------------------------------------$
		char `$
		char overflow val ,$
		Decimal 96$
		Decimal Ptr -664082596$
		Int 96$
		Int Ptr -664082596$
		Unsigned + 96$
		Unsigned - 4294967200$
		Pointer at memory 0x7ffdd86ae75c$
		Pointer at value 0x60$
		hex positive 60$
		hex negative ffffffa0$
		hexadecimal on long ffffffff$
		$
		String size 245$
		$
		___________________________________________________________________$
		Test 2 - $
		-------------------------------------------------------------------$
		$
		String size of just % -1$
		$
		___________________________________________________________________$
		Test 3 - Undefined$
		-------------------------------------------------------------------$
		0x0.0723a71c046a8p-1022ve more$
		$
		String size of % and more 32$
		$
		___________________________________________________________________$
		Test 4 - Undefined$
		-------------------------------------------------------------------$
		6.20523e-310wa have more and a valid int 96$
		$
		String size of % with param 45$
		$
		___________________________________________________________________$
		Test 5 - $
		-------------------------------------------------------------------$
		96 hello am i working$
		$
		String size of % with spaces between 23$
		$
		___________________________________________________________________$
		Test 6 - $
		-------------------------------------------------------------------$
		%$
		$
		$
		String size of % with whitespaces between 6$
		$
		___________________________________________________________________$
		Test 7 - $
		-------------------------------------------------------------------$
		% $
		i hello am i working$
		$
		String size of % with whitespaces between  and more 24$
		$
		___________________________________________________________________$
		Test 8 - $
		-------------------------------------------------------------------$
		(null)$
		$
		String size of null string 7$
		$
		___________________________________________________________________$
		Test 9 - $
		-------------------------------------------------------------------$
		(nil)$
		$
		String size of null ptr 6$
		$
		___________________________________________________________________$
		Test 10 - $
		-------------------------------------------------------------------$
		(nil)$
		$
		String size of null not inicialiazed ptr 6$
		$
		___________________________________________________________________$
		Test 11 - $
		-------------------------------------------------------------------$
		$
		String size of null input string -1$
		$
		___________________________________________________________________$







	conclusions
		%d and %i does the same thing
		%u is unsigned if it is positive it loops arround and subracts value
		%p just converts int value to hexadecimal with 0x at the beginning
		%x uses unsigned int to convert number it its a long just converts to max int
		
		7fff654702d0
		ffffffffffffs

		if its just % returns -1
		% with non flag is undefined behaviour just return -1
		null str prints (null) and returns its size breaks when str is not inicialized
		null pointer prints (nil) and returns its size even if not inicialized
	*/

}