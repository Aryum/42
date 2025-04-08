#name
NAME = libft.a

#folders
SOURCE_DIR = srcs

HEADER_DIR = includes

#files

SOURCE_FILES = 	$(SOURCE_DIR)/ft_putchar \
				$(SOURCE_DIR)/ft_putstr \
				$(SOURCE_DIR)/ft_strcmp \
				$(SOURCE_DIR)/ft_strlen \
				$(SOURCE_DIR)/ft_swap 

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

#compiler
CC = cc

FLAGS = -c -Wall -Wextra -Werror -I$(HEADER_DIR) 

#rules
all: $(NAME)

$(NAME) : $(OBJECT_FILES)
	ar r $(NAME)

%.o : %.c
	$(CC) $(FLAGS) $< -o $(<:.c=.o) 

clean:
	rm $(OBJECT_FILES)

fclean: clean
	rm $(NAME)

re:fclean all