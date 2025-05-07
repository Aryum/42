/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/07 11:13:38 by ricsanto         ###   ########.fr       */
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


#include "ft_printf.h"

static void formatstr(char c, va_list args, int *counter)
{
	if (c == 'c')
		h_put_char(va_arg(args, int),counter);
	else if (c == 's')
		h_put_str(va_arg(args, char *),counter);
	else if (c == 'p')
		h_put_ptr(va_arg(args, void *),counter);
	else if (c == 'd' || c == 'i')
		h_put_int(va_arg(args, int),counter);
	else if (c == 'u') 
		h_put_uint(va_arg(args, unsigned int),counter);
	else if (c == 'x')
		h_put_uintbase(va_arg(args, unsigned int),"0123456789abcdef",counter);
	else if (c == 'X')
		h_put_uintbase(va_arg(args, unsigned int),"0123456789ABCDEF",counter);
	else if (c == '%')
		h_put_char('%',counter);
	else
		*counter = -1;
}

int ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	arg_v;
	
	if(str == NULL || write(1,0,0) == -1)
		return (-1);
	ret = 0;
	i = 0;
	va_start(arg_v, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			h_put_char(str[i], &ret);
		else
		{
			formatstr(str[i + 1], arg_v, &ret);
			if(ret != -1)
				i++;
		}
		i++;
	}
	va_end(arg_v);
	return (ret);
}
/*
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

