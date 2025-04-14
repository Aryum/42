/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:42:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/11 15:32:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests_char.h"
#include <ctype.h>



int main(int agrc, char **argv)
{
	char_logMessages(isprint, ft_isprint, agrc != 1);
	return 0;
}