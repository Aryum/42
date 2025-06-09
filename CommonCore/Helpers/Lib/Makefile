# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:57:37 by ricsanto          #+#    #+#              #
#    Updated: 2025/06/06 11:02:04 by ricsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lib.a

FLAGS := -Wall -Wextra -Werror

SRC :=	lib_isalpha.c	lib_isdigit.c	lib_isalnum.c	lib_isascii.c	lib_isprint.c	\
		lib_strlen.c		lib_memset.c		lib_bzero.c		lib_memcpy.c		lib_memmove.c	\
		lib_strlcpy.c	lib_strlcat.c	lib_toupper.c	lib_tolower.c	lib_strchr.c		\
		lib_strrchr.c	lib_strncmp.c	lib_memchr.c		lib_memcmp.c		lib_strnstr.c	\
		lib_atoi.c		lib_calloc.c		lib_strdup.c		lib_substr.c		lib_strjoin.c	\
		lib_strtrim.c	lib_split.c		lib_itoa.c		lib_strmapi.c	lib_striteri.c	\
		lib_putchar_fd.c	lib_putstr_fd.c	lib_putendl_fd.c lib_putnbr_fd.c

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
