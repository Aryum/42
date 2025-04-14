/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:58:43 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/12 01:58:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int isclass(int c, int lower, int upper)
{
	return(c >= lower && c <= upper);
}

int toupper(int c)
{
	if(isclass(c, 'a', 'z'))
		return (c - 32);
	return (c);
}