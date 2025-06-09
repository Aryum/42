/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:35:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 12:54:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/psr.h"

static int get_nbrs(t_list **lst, char *c)
{
	int		i;
	char	**nbr_str;
	long	current;

	i = 0;
	current = 0;
	nbr_str = lib_split(c, ' ');
	while (nbr_str[i] != NULL)
	{
		if (psr_h_try_get_number(nbr_str[i], &current))
		{
			if(!psr_h_try_add_number(lst,current))
			{
				lib_split_clean(nbr_str,i);
				return (0);
			}
		}
		i++;
	}
	lib_split_clean(nbr_str,i);
	return (1);
}

int	psr_agrs(t_list **lst, int argc, char **argv)
{
	int		i;
	
	i = 0;
	while (i < argc)
	{
		if(!get_nbrs(lst, argv[i]))
		{
			lst_clear(lst);
			return (0);
		}
		i++;
	}
	return (1);
}
