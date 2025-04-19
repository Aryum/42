/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:55:25 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/07 10:56:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_base_valid(char *str, int *basesize)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
				return (0);
			if ((str[i] > 8 && str[i] <= '\r') || str[i] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	if (basesize != (void *)0)
		*basesize = i;
	return (1);
}

int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	find_last_index(char *str, char *base, int *last_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (index_in_base(str[i], " \b\t\n\v\f\r") != -1)
		i++;
	while (index_in_base(str[i], "+-") != -1)
		i++;
	if (index_in_base(str[i], base) != -1)
	{
		while (index_in_base(str[i + 1], base) != -1)
			i++;
		*last_index = i;
		return (1);
	}
	return (0);
}

int	convert_nbr(char c, char *base, int pwr, int base_sz)
{
	int	i;
	int	mult;
	int	base_index;

	i = 0;
	mult = 1;
	base_index = index_in_base(c, base);
	if (base_index != -1)
	{
		if (pwr != 0)
		{
			while (i < pwr)
			{
				mult *= base_sz;
				i++;
			}
		}
		return (mult * base_index);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	last_index;
	int	base_sz;
	int	i;
	int	ret_value;
	int	simbol;

	i = 0;
	simbol = 1;
	ret_value = 0;
	if (!is_base_valid(base, &base_sz))
		return (0);
	if (find_last_index(str, base, &last_index))
	{
		while (last_index - i >= 0)
		{
			if (index_in_base(str[last_index - i], base) != -1)
				ret_value += convert_nbr(str[last_index - i], base, i, base_sz);
			else if (str[last_index - i] == '-')
				simbol *= -1;
			i++;
		}
	}
	return (ret_value * simbol);
}
