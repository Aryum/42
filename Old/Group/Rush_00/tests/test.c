#include<unistd.h>
#pragma region rush00

void	write_collums_bound_upper0(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "o", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "o", 1);
		}
		else
		{
			write(1, "-", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_bound_lower0(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "o", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "o", 1);
		}
		else
		{
			write(1, "-", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_middle0(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1 || *current_collums == x)
		{
			write(1, "|", 1);
		}
		else
		{
			write(1, " ", 1);
		}
		(*current_collums)++;
	}
}

#pragma endregion

#pragma region rush01
void	write_collums_bound_upper1(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "/", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "\\", 1);
		}
		else
		{
			write(1, "*", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_bound_lower1(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "\\", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "/", 1);
		}
		else
		{
			write(1, "*", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_middle1(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1 || *current_collums == x)
		{
			write(1, "*", 1);
		}
		else
		{
			write(1, " ", 1);
		}
		(*current_collums)++;
	}
}

#pragma endregion

#pragma region rush02

void	write_collums_bound_upper2(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "A", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "A", 1);
		}
		else
		{
			write(1, "B", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_bound_lower2(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "C", 1);
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

void	write_collums_middle2(int x, int *current_collums)
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

#pragma endregion

#pragma region rush03

void	write_collums_bound_upper3(int x, int *current_collums)
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

void	write_collums_bound_lower3(int x, int *current_collums)
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

void	write_collums_middle3(int x, int *current_collums)
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
#pragma endregion

#pragma region rush04
void	write_collums_bound_upper4(int x, int *current_collums)
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

void	write_collums_bound_lower4(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "C", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "A", 1);
		}
		else
		{
			write(1, "B", 1);
		}
		(*current_collums)++;
	}
}

void	write_collums_middle4(int x, int *current_collums)
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
#pragma endregion

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
			write_collums_bound_upper4(x, &current_collums);
		}
		else if (current_line == y)
		{
			write_collums_bound_lower4(x, &current_collums);
		}
		else
		{
			write_collums_middle4(x, &current_collums);
		}
		write(1, "\n", 1);
		current_collums = 1;
		current_line ++;
	}
}

int	main(void)
{
	ft_putchar(5, 3);
	return (0);
}