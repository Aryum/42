/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:00:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/11 12:17:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include "tests_char.h"


int main(int agrc, char **argv)
{
	char_logMessages(isalnum, ft_isalnum, agrc != 1);
	return 0;
}