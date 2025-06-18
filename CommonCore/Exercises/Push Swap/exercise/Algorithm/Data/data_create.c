/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:58 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:23:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_stack *ini_stack(t_id id)
{
	t_stack *ret;

	ret = malloc(sizeof(t_stack));
	if (ret != NULL)
	{
		ret->lst = NULL;
		ret->size = 0;
		ret->id = id;
	}
	return (ret);
}

t_stack_data	data_ini()
{
	t_stack_data	ret;

	ret.a = ini_stack(a);
	ret.b = ini_stack(b);
	if (ret.a == NULL || ret.b == NULL)
		data_clear(ret);
	return (ret);
}
