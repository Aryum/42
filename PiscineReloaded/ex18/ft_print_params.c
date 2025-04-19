/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:14:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 11:28:54 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int agrc, char **argv)
{
	int	i;
	int	h;

	i = 1;
	h = 0;
	while (i < agrc)
	{
		while (argv[i][h] != '\0')
		{
			ft_putchar(argv[i][h]);
			h++;
		}
		ft_putchar('\n');
		h = 0;
		i++;
	}
	return (0);
}
