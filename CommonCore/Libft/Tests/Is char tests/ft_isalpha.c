/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo-santos <ricardo-santos@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:09:35 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/10 14:55:51 by ricardo-san      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int isclass(int c, int lower, int upper)
{
	return(c >= lower && c <= upper);
}

int ft_isalpha(int c)
{
	if(isclass(c, 0, 255))
		return (isclass(c, 'a', 'z') || isclass(c, 'A', 'Z'));
	return (0);
}

