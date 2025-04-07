/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:30:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/26 12:30:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_collums_bound_upper(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "A", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "C", 1);
		}
		else
		{
			write(1, "B", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_bound_lower(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "A", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "C", 1);
		}
		else
		{
			write(1, "B", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_middle(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1 || *current_collums == x)
		{
			write(1, "B", 1);
		}
		else
		{
			write(1, " ", 1);
		}
		(*current_collums)++;
	}
}

void	ft_putchar(int x, int y)
{
	int	current_line;
	int	current_collums;

	current_collums = 1;
	current_line = 1;
	while (current_line <= y)
	{
		if (current_line == 1)
		{
			write_collums_bound_upper(x, &current_collums);
		}
		else if (current_line == y)
		{
			write_collums_bound_lower(x, &current_collums);
		}
		else
		{
			write_collums_middle(x, &current_collums);
		}
		write(1, "\n", 1);
		current_collums = 1;
		current_line ++;
	}
}

int	main(void)
{
	ft_putchar(1, 5);
	return (0);
}
