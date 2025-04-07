#file paths
SOURCE_DIR = srcs

SOURCE_FILES = 	$(SOURCE_DIR)/ft_putchar.c \
				$(SOURCE_DIR)/ft_putstr.c \
				$(SOURCE_DIR)/ft_strcmp.c \
				$(SOURCE_DIR)/ft_strlen.c \
				$(SOURCE_DIR)/ft_swap.c \

				
HEADER_DIR = includes

LIB = libft.a

#compile settings
CC = cc

FLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) -c

#rules
all:
	$(CC) $(FLAGS) $(SOURCE_FILES)
	ar r $(LIB) *.o
clean :
	rm *.o

fclean : clean
	rm $(LIB)
re: fclean all

