void	write_collums_bound_upper(int x, int *current_collums)
{
	while (*current_collums <= x)
	{
		if (*current_collums == 1)
		{
			write(1, "CHANGE VALUE", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "CHANGE VALUE", 1);
		}
		else
		{
			write(1, "CHANGE VALUE", 1);
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
			write(1, "CHANGE VALUE", 1);
		}
		else if (*current_collums == x)
		{
			write(1, "CHANGE VALUE", 1);
		}
		else
		{
			write(1, "CHANGE VALUE", 1);
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
			write(1, "CHANGE VALUE", 1);
		}
		else
		{
			write(1, " ", 1);
		}
		(*current_collums)++;
	}
}
