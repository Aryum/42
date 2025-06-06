NAME := lib.a

FLAGS := -Wall -Wextra -Werror

SRC := 	lib_bzero.c		lib_calloc.c	lib_memset.c	lib_split.c \
		lib_strlcpy.c	lib_strdup.c	lib_strlen.c	lib_substr.c

OBJ := $(SRC:.c=.o)

AR := ar -rcs

RM := rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	cc $(FLAGS) -o $@ -c $< -I.

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re