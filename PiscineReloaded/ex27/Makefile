#file paths
SOURCE_FILES = 	ft_display_file.c 

OBJ_FILES = $(SOURCE_FILES:.c=.o)

NAME = ft_display_file

#compile settings
CC = cc

FLAGS = -Wall -Wextra -Werror

#rules
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c  $(SOURCE_FILES) -o $(SOURCE_FILES:.c=.o)
	$(CC) $(FLAGS)  $(OBJ_FILES) -o $(NAME)


clean: 
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
