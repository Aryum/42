NAME := lst.a

SRC := 	lst_new.c		lst_add_front.c	lst_size.c	lst_last.c	\
		lst_add_back.c	lst_delone.c	lst_clear.c	lst_iter.c	\
		lst_map.c

HDR_DIR := .

FLAGS := -Wall -Wextra -Werror

AR := ar -rcs

RM := rm -f

blank :=
define NEWLINE

$(blank)
endef

COLOUR_GREEN := \033[1;32m
COLOUR_RED := \033[1;31m
COLOUR_YELLOW := \033[1;33m
COLOUR_BLUE := \033[1;34m

all: $(NAME)

$(NAME): $(SRC)
	@$(foreach cfile,$(SRC), cc $(FLAGS) -o $(cfile:.c=.o) -c $(cfile) -I$(HDR_DIR) $(NEWLINE))
	@$(AR) $@ $(SRC:.c=.o)
	@echo "$(COLOUR_GREEN)	Making $(NAME)"
	@$(RM) $(SRC:.c=.o)

clean:
	@$(RM) $(SRC:.c=.o)
	@echo "$(COLOUR_YELLOW)	Cleaning objects of $(NAME)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)	Cleaning $(NAME)"

re: fclean all

.PHONY: all clean fclean re
