/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:16:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/11 12:16:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "tests_char.h"


int test(int c)
{
	return ((c) & ~0x7f) == 0;
}
int main(int agrc, char **argv)
{
	char_logMessages(test, ft_isascii, agrc != 1);
	return 0;
}