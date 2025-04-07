/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:27:59 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/11 09:30:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*create_str(char *str, int start, int end)
{
	char	*ret;
	int		i;

	ret = malloc((end - start) + 1);
	i = 0;
	while (start + i < end)
	{
		ret[i] = str[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	is_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *set)
{
	int	i;
	int	flag;
	int	counter;

	flag = 0;
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (flag == 0 && is_charset(str[i], set))
			flag = 1;
		if (flag == 1 && !is_charset(str[i], set))
			flag = 2;
		if (flag == 2 && is_charset(str[i], set))
		{
			flag = 1;
			counter ++;
		}
		i++;
	}
	return (counter);
}

void	fill(char **arr, char *str, char *set)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], set))
		{
			flag = 1;
			if (len != 0)
			{
				*arr = create_str(str, i - len - 1, i + 1);
				arr++;
				len = 0;
			}
		}
		if (flag && !is_charset(str[i], set))
			len++;
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ret_val;
	int		word_c;

	word_c = word_count(str, charset);
	ret_val = malloc ((word_c + 1) * sizeof(char *));
	fill(ret_val, str, charset);
	ret_val[word_c] = ((void *)0);
	return (ret_val);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	char *str = "-hello+world";
	char *set = "-+";
	char **val = ft_split(str,set); 
	while(val[i] != (void *)0)
	{
		printf("%d index (%s)\n",i ,val[i]);
		free(val[i]);
		i++;
	}
	free(val);
	return 0;
}
*/