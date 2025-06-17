/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:19:11 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 18:13:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_H
# define ALG_H

# include "../../Helpers/Lst/lst.h"

typedef struct s_stack
{
	t_list	*lst;
	int		size;
	int		mid;
	char	id;
	
} t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
} t_data;

# include "../Debug/dbg.h"
# include "../Moves/mv.h"
# include "../Parser/psr.h"
//# include "../RotateToPush/rtp.h"




#endif