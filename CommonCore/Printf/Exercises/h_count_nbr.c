/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_count_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:17:59 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 13:34:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	h_count_nbr(long int nbr)
{
	int	counter;

	counter = 1;
	if(nbr < 0)
	{
		counter ++;
		nbr *= -1;
	}
	while(nbr / 10 > 0)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}