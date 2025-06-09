/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:35:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 18:18:54 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/psr.h"

static int	get_nbrs(t_list **lst, char *c)
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
			if (!psr_h_try_add_number(lst, (int)current))
				return (lib_split_clean(nbr_str), 0);
		}
		else
			return (lib_split_clean(nbr_str), 0);
		i++;
	}
	return (lib_split_clean(nbr_str), 1);
}

int	psr_agrs(t_list **lst, int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return (print_f("No arguments passed\n"), 0);
	i = 1;
	while (i < argc)
	{
		if (!get_nbrs(lst, argv[i]))
			return (lst_clear(lst), 0);
		i++;
	}
	return (1);
}
