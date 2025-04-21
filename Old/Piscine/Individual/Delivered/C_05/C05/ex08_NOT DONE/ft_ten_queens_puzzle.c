/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:21:31 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/02 13:21:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

//returns if it has a queen
int check_row(int start_x, int grid[10][10])
{
	int i;
	int has_queen;

	i = 0;
	has_queen = 0;
	while(i < 10)
	{
		if(grid[start_x][i])
		{
			if(has_queen)
			{
				break ;
			}
			else
			{
				has_queen = 1;
			}
		}
		i++;
	}
	return (has_queen);
}
int check_column(int start_y, int grid[10][10])
{
	int i;
	int has_queen;

	i = 0;
	has_queen = 0;
	while(i < 10)
	{
		if(grid[i][start_y])
		{
			if(has_queen)
			{
				break ;
			}
			else
			{
				has_queen = 1;
			}
		}
		i++;
	}
	return (0);
}
int is_diagonal(int x, int y)
{
	
}
int	check_diagonal(int grid[10][10])
{
	
}
int ft_ten_queens_puzzle(void)
{
	return 0;
}
int main()
{
	int grid[10][10] = {{0,0,0,1,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}};

	int start_x = 0;
	int start_y = 0;

	while(start_x < 10)
	{
		if(check_row(start_x, grid))
		{
			printf("Row %d has multiple queens\n",start_x);
		}
		while(start_y < 10)
		{
			if(check_column(start_y, grid))
			{
				printf("column %d has multiple queens\n", start_y);
			}
			start_y++;
		}
		start_x++;
	}
	check_diagonal(grid);
	return 0;
}
*/