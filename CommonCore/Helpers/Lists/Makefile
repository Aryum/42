NAME := lst_.a

FLAGS := -Wall -Wextra -Werror

SRC := 	lst_new.c		lst_add_front.c	lst_size.c	lst_last.c	\
		lst_add_back.c	lst_delone.c	lst_clear.c	lst_iter.c	\
		lst_map.c

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