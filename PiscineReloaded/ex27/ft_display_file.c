/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo-santos <ricardo-santos@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:47:32 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/09 09:48:54 by ricardo-san      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	displayfile(int file)
{
	size_t	readbytes;
	char	buffer;

	readbytes = read(file, &buffer, 1);
	while (readbytes > 0)
	{
		write(1, &buffer, 1);
		readbytes = read(file, &buffer, 1);
	}
}

int	main(int argc, char **argv)
{
	int	file;

	if (argc != 2)
	{
		if (argc == 1)
			putstr("File name missing.");
		else
			putstr("Too many arguments.");
		return (0);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		putstr("Cannot read file.");
		return (0);
	}
	displayfile(file);
	close(file);
	return (1);
}
