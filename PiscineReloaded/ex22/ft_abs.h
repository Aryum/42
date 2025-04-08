/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:35:10 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/08 11:08:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(val) (abs(val))

int	abs(int value)
{
    if (value < 0)
        return (-value);
    else
        return (value);
}
