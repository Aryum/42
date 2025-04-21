/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:54:10 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/12 13:24:14 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	str_cat(char *dest, char *source)
{
	int	i;

	i = 0;
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	return (i);
}

int	calculate_total(int size, char **strs, char *sep)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += str_size(strs[i]);
		if (i + 1 < size)
			ret += str_size(sep);
		i++;
	}
	return (ret + 1);
}

int	alloc(char **str, int length)
{
	*str = malloc(sizeof(char) * length);
	return (*str != ((void *)0));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		h;
	char	*ret;
	int		i;
	int		total;

	i = 0;
	h = 0;
	if (size > 0)
	{
		total = calculate_total(size, strs, sep);
		if (alloc(&ret, total))
		{
			while (h < total - 1)
			{
				h += str_cat(&ret[h], strs[i]);
				if (i + 1 < size)
					h += str_cat(&ret[h], sep);
				i++;
			}
		}
	}
	else
		ret = malloc(1);
	ret[h] = '\0';
	return (ret);
}
/*
#include <stdio.h>
int main()
{
	char *strs[10] = {"Hello", "world", "world"};
	char *c = ft_strjoin(3,strs,"+-+");
	printf("%s\n", c);
	free(c);
}
*/