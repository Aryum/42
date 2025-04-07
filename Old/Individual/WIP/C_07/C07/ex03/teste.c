/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:34:21 by miduarte          #+#    #+#             */
/*   Updated: 2025/02/12 13:23:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_arraylen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	seplen;
	int	abslen;

	i = 0;
	j = 0;
	abslen = 0;
	while (i < size)
	{
		abslen += ft_strlen(strs[i]);
		i++;
	}
	seplen = ft_strlen(sep);
	abslen += seplen * (size - 1);
	return (abslen);
}

char	*ft_alloc(int size, char **strs, char *sep)
{
	char	*result;
	int		len;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	len = ft_arraylen(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (len + 1));
	printf("%d\n",len + 1);

	if (result == NULL)
	{
		return (NULL);
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	k = 0;
	result = ft_alloc(size, strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			result[k++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
			result[k++] = sep[j++];
		i++;
	}
	result[k] = '\0';
	return (result);
}

int main()
{
	char *strs[10] = {"Hello", "world", "world"};
	char *c = ft_strjoin(3,strs,"+-+");
	printf("%s\nis null ? %s", c, c[0] == '\0' ? "yes" : "no");

}
*/