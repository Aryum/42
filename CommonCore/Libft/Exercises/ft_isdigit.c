/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo-santos <ricardo-santos@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:34:48 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/10 12:36:02 by ricardo-san      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int isclass(int c, int lower, int upper)
{
	return(c >= lower && c <= upper);
}

int ft_isdigit(int c)
{
	if(isclass(c, 0, 255))
		return (isclass(c, '0', '9'));
	return (0);
}
