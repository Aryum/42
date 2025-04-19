/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:54:27 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 17:31:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(char **arr, int len)
{
	int	i;
	int	h;
	int	swapped;

	i = 0;
	h = 1;
	swapped = 0;
	while (i < len - 1)
	{
		while (h < len - i - 1)
		{
			if (cmp(arr[h], arr[h + 1]) > 0)
			{
				swap(&(arr[h]), &(arr[h + 1]));
				swapped = 1;
			}
			h++;
		}
		if (swapped == 0)
			break ;
		h = 0;
		i++;
	}
}

int	main(int agrc, char **agrv)
{
	int	i;
	int	h;

	h = 0;
	i = 1;
	sort(agrv, agrc);
	while (i < agrc)
	{
		while (agrv[i][h] != '\0')
		{
			ft_putchar(agrv[i][h]);
			h++;
		}
		ft_putchar('\n');
		h = 0;
		i++;
	}
	return (0);
}
