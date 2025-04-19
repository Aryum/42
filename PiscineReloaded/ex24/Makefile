#file paths
SOURCE_DIR = srcs

SOURCE_FILES = 	$(SOURCE_DIR)/ft_putchar.c \
				$(SOURCE_DIR)/ft_putstr.c \
				$(SOURCE_DIR)/ft_strcmp.c \
				$(SOURCE_DIR)/ft_strlen.c \
				$(SOURCE_DIR)/ft_swap.c \

OBJ_FILES = $(SOURCE_FILES:.c=.o)

HEADER_DIR = includes

NAME = libft.a

#compile settings
CC = cc

FLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) -c

#rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar r $(NAME) $?

%.o: %.c
	$(CC) $(FLAGS) $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:fclean all

