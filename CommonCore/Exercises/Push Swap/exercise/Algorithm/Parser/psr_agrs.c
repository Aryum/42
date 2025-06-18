/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:35:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:16:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

static int	get_nbrs(t_stack *stack, char *c)
{
	int		i;
	char	**nbr_str;
	long	current;

	i = 0;
	nbr_str = lib_split(c, ' ');
	while (nbr_str[i] != NULL)
	{
		current = 0;
		if (psr_h_try_get_number(nbr_str[i], &current))
		{
			if (!psr_h_try_add_number(stack, (int)current))
				return (lib_split_clean(nbr_str), 0);
		}
		else
			return (lib_split_clean(nbr_str), 0);
		i++;
	}
	return (lib_split_clean(nbr_str), 1);
}

int	psr_agrs(t_stack_data data, int argc, char **argv)
{
	int	arg_i;

	if (argc == 1)
		return (print_f("Error\n"), 0);
	arg_i = 1;
	while (arg_i < argc)
	{
		if (!get_nbrs(data.a, argv[arg_i]))
		{
			print_f("Error\n");
			lst_clear(&(data.a->lst));
			return (0);
		}
		arg_i++;
	}
	psr_h_indexer(data.a->lst);
	data.total_size = data.a->size;
	return (1);
}
