# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 19:21:29 by ricsanto          #+#    #+#              #
#    Updated: 2025/06/06 11:54:51 by ricsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := print.a

FLAGS := -Wall -Wextra -Werror

SRC :=	print_f.c			print_h_put_char.c	print_h_put_nbr.c	print_h_put_base.c	\
		print_h_put_ptr.c	print_h_put_str.c	print_h_strlen.c

OBJ := $(SRC:.c=.o)

AR := ar -rcs

RM := rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	cc $(FLAGS) -o $@ -c $< -I.

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
