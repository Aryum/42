NAME := chk.a

SRC := 	chk_edges.c	\
		chk_sort.c	\
		chk_chunk.c
		
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
COLOR_WHITE := \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(foreach cfile,$(SRC), cc $(FLAGS) -o $(cfile:.c=.o) -c $(cfile) -I$(HDR_DIR) $(NEWLINE))
	@$(AR) $@ $(SRC:.c=.o)
	@echo "$(COLOUR_GREEN)	Making $(NAME)$(COLOUR_WHITE)"
	@$(RM) $(SRC:.c=.o)

clean:
	@$(RM) $(SRC:.c=.o)
	@echo "$(COLOUR_YELLOW)	Cleaning objects of $(NAME)$(COLOUR_WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)	Cleaning $(NAME)$(COLOUR_WHITE)"

re: fclean all

.PHONY: all clean fclean re

