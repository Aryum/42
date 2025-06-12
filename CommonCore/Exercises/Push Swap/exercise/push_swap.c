/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/11 08:52:42 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(int i)
{
	print_f("	%d\n", i);
}

void	printlists(t_stacks stacks, char *str)
{
	print_f("%s\n", str);
	print_f("---------------------------------------\n");
	print_f("A\n");
	lst_iter(stacks.a, print);
	print_f("B\n");
	lst_iter(stacks.b, print);
	print_f("---------------------------------------\n\n\n");
}
//int	main(int argc, char **argv)

int	main()
{
	t_stacks stacks;

	stacks.a = NULL; 
	stacks.b = NULL;

	//psr_agrs(&(stacks.a), argc, argv);
	printlists(stacks, "Og list");
	
	srt_push_b(&stacks);
	printlists(stacks, "Push b");

	srt_push_a(&stacks);
	printlists(stacks, "Push b");

	srt_rotate_rev_a(&stacks);
	printlists(stacks, "rev rotate a");
	
	srt_rotate_a(&stacks);
	printlists(stacks, "rotate a");
	
	srt_swap_a(&stacks);
	printlists(stacks, "Swap a");


	
	lst_clear(&stacks.a);
	lst_clear(&stacks.b);

}
