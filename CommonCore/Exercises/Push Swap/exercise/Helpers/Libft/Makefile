NAME := lb.a

FLAGS := -Wall -Wextra -Werror

SRC := 	lb_bzero.c		lb_calloc.c	lb_memset.c	lb_split.c \
		lb_strlcpy.c	lb_strdup.c	lb_strlen.c	lb_substr.c

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