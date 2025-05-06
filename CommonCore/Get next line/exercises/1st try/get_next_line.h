/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:45:44 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/06 16:26:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFERSIZE
#  define BUFFERSIZE 50000
# endif
 
#include <unistd.h>
#include <stdlib.h>

typedef struct s_strinfo
{
	size_t	size;
	int 	endline;
} t_strinfo;


#endif