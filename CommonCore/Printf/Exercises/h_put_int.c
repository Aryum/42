/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:40:28 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 12:48:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void h_put_int(int n, int *counter)
{
	int		correction;

	correction = 0;
	if (n < 0)
	{
		h_putchar("-", counter);
		if (n == -2147483648)
			correction = 1;
		n = -1 * (n + correction);
	}
	if (n > 9)
		print_nbr(n / 10, counter);
	h_putchar(n % 10 + '0' + correction, counter);
}