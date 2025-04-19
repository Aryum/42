/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:39:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/10 11:48:31 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN is_even

int	is_even(int v)
{
	return (v % 2 == 0);
}

# define EVEN_MSG "I have an even number of arguments.\n"

# define ODD_MSG  "I have an odd number of arguments.\n"

# define SUCCESS 1

# define FAILURE 0

typedef enum Boolean
{
	FALSE,
	TRUE
}	t_bool;
#endif
