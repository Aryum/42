/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:40:16 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/06 17:30:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H
# define ABS abs

int	abs(int val)
{
	if (val < 0)
		val *= -1;
	return (val);
}
#endif
