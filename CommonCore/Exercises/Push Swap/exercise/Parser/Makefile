NAME := psr.a

SRC := 	psr_agrs.c	psr_h_try_add_lst.c	psr_h_try_get_number.c

HDR_DIR := Headers

OBJ := $(SRC:.c=.o)

FLAGS := -Wall -Wextra -Werror

AR := ar -rcs

RM := rm -f

COLOUR_GREEN := \033[1;32m
COLOUR_RED := \033[1;31m
COLOUR_YELLOW := \033[1;33m
COLOUR_BLUE := \033[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "$(COLOUR_GREEN)	Making $(NAME)"

%.o: %.c $(HEADER)
	@cc $(FLAGS) -o $@ -c $< -I$(HDR_DIR)

clean:
	@$(RM) $(OBJ) 
	@echo "$(COLOUR_YELLOW)	Cleaning objects of $(NAME)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)	Cleaning $(NAME)"

re: fclean all
	@echo "$(COLOUR_BLUE)	Remaking $(NAME)"

.PHONY: all clean fclean re