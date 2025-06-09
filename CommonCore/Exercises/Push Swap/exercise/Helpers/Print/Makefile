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

SRC :=	print_f.c			print_h_put_char.c	print_h_put_nbr.c	print_h_put_base.c	\
		print_h_put_ptr.c	print_h_put_str.c	print_h_strlen.c

HDR_DIR := .

OBJ := $(SRC:.c=.o)

FLAGS := -Wall -Wextra -Werror

AR := ar -rcs

RM := rm -f

COLOUR_GREEN := \033[1;32m
COLOUR_RED := \033[1;31m
COLOUR_YELLOW := \033[1;33m
COLOUR_BLUE := \033[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "$(COLOUR_GREEN)	Making $(NAME)"

%.o: %.c $(HEADER)
	@cc $(FLAGS) -o $@ -c $< -I$(HDR_DIR)

clean:
	@$(RM) $(OBJ) 
	@echo "$(COLOUR_YELLOW)	Cleaning objects of $(NAME)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)	Cleaning $(NAME)"

re: fclean all
	@echo "$(COLOUR_BLUE)	Remaking $(NAME)"

.PHONY: all clean fclean re
