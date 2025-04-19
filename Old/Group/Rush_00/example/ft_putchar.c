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
