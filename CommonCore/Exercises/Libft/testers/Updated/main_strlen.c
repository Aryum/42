/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:05:00 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/11 14:05:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include "tests_str.h"


int main(int agrc, char **argv)
{
	strlen_logMessages(strlen, ft_strlen, agrc != 1);
	return 0;
}