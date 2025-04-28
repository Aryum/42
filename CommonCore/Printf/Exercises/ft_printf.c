/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/28 11:33:16 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prtf.h"

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
			if(str[i + 1] == 'p')
				write (1, "ptr", 4);
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
	printf("Pointer adress int\n");
	printf("%ls\n", &a);
}