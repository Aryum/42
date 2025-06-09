/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 18:15:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(int i)
{
	print_f("%d\n", i);
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = NULL;
	psr_agrs(&lst, argc, argv);
	lst_iter(lst, print);
	lst_clear(&lst);
}
