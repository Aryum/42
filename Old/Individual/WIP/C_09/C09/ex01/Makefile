SOURCE_DIR = srcs

SOURCE_FILES =  $(SOURCE_DIR)/ft_putchar.c	\
				$(SOURCE_DIR)/ft_swap.c		\
				$(SOURCE_DIR)/ft_putstr.c	\
				$(SOURCE_DIR)/ft_strlen.c	\
				$(SOURCE_DIR)/ft_strcmp.c

HEADER_DIR = includes

HEADER_FILES = ft.h

CC = cc

C_FLAGS = -Wall -Wextra -Werror -include $(HEADER_DIR)/$(HEADER_FILES) -c

LIB = libft.a

all:
	$(CC) $(C_FLAGS) $(SOURCE_FILES) 
	ar r *.o

