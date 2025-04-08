/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:19:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 18:11:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int			i;
	long int	result;

	result = 1;
	i = 0;
	while (result < nb && result < 2147483648)
	{
		result = i * i;
		if (result == nb)
			return (i);
		i++;
	}
	return (0);
}
