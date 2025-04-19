/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:52:23 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/08 11:09:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	ret_val;

	i = 0;
	ret_val = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
		{
			ret_val++;
		}
		i++;
	}
	return (ret_val);
}
