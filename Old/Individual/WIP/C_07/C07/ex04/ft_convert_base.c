/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:54:42 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/12 13:30:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_base_valid(char *str, int *basesize);

int	ft_atoi_base(char *str, char *base);

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	alloc_str(int nbr, int base_size, char **str)
{
	int	i;

	i = 1;
	if (nbr < 0)
		i += 1;
	while (nbr / base_size != 0)
	{
		nbr /= base_size;
		i++;
	}
	*str = malloc(sizeof(char) * (i + 1));
	if (*str != ((void *)0))
		return (i + 1);
	else
		return (-1);
}

char	*getrev(int nbr, char *base, int base_sz, int len)
{
	char	*reverse_str;
	int		i;

	i = 0;
	reverse_str = malloc(len);
	if (reverse_str != ((void *)0))
	{
		reverse_str[len - 1] = '\0';
		if (nbr < 0)
		{
			reverse_str[len - 2] = '-';
			nbr *= -1;
		}
		while (i < len)
		{
			if (nbr != 0)
				reverse_str[i] = base[nbr % base_sz];
			nbr /= base_sz;
			i++;
		}
		i = 0;
	}
	return (reverse_str);
}

char	*get_str(int nbr, char *base, int base_sz)
{
	char	*reverse_str;
	int		i;
	int		str_sz;
	char	*ret_val;

	ret_val = ((void *)0);
	i = 0;
	str_sz = alloc_str(nbr, base_sz, &ret_val);
	reverse_str = getrev(nbr, base, base_sz, str_sz);
	if (ret_val != ((void *)0) && reverse_str != ((void *)0))
	{
		while (i < str_sz - 1)
		{
			ret_val[i] = reverse_str[str_sz - i - 2];
			i++;
		}
		ret_val[str_sz] = '\0';
	}
	if (reverse_str != ((void *)0))
		free(reverse_str);
	return (ret_val);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec_val;
	int		to_sz;
	int		from_sz;

	to_sz = 0;
	from_sz = 0;
	if (is_base_valid(base_from, &from_sz) && is_base_valid(base_to, &to_sz))
	{
		dec_val = ft_atoi_base(nbr, base_from);
		return (get_str(dec_val, base_to, to_sz));
	}
	return ((void *)0);
}

/*
#include <stdio.h>

int main()
{
	char *c = "0";
	c = ft_convert_base("      -101010 010101","01", "0123456789ABCDEF");
	free (c);

	printf("%s\n", c );
	c = ft_convert_base("      101010 010101","01", "0123456789");
	printf("%s", c );

	free (c);
	return 0;
}
*/