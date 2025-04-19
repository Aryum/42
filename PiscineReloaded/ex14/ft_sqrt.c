/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo-santos <ricardo-santos@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:19:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/09 09:08:44 by ricardo-san      ###   ########.fr       */
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
