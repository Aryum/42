/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo-santos <ricardo-santos@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:52:23 by ricardo-san       #+#    #+#             */
/*   Updated: 2025/04/07 10:58:32 by ricardo-san      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	retVal;
	
	i = 0;
	retVal = 0;
	while(tab[i] != 0)
	{
		if(f(tab[i]) == 1)
		{
			retVal++;
		}
		i++;	
	}

	return retVal;
}

