/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:09:35 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/11 10:54:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int isclass(int c, int lower, int upper)
{
	return(c >= lower && c <= upper);
}

int ft_isalpha(int c)
{
	if (isclass(c, 0, 255))
	{
		if(isclass(c, 'a', 'z') || isclass(c, 'A', 'Z'))
			return (1024);	
	}
	return (0);
}

