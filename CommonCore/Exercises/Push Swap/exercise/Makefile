NAME := push_swap

NAME_C := $(NAME).c
HDR_DIR = .

#Libs
HLP_DIR := Helpers
HLP_ARC := $(HLP_DIR)/Lib/lib.a $(HLP_DIR)/Lst/lst.a $(HLP_DIR)/Print/print.a

PSR_DIR := Parser
PSR_ARC := $(PSR_DIR)/psr.a



ALL_ARC := $(HLP_ARC) $(PSR_ARC)

#Vars
MAKEFLAGS += --no-print-directory

FLAGS := -Wall -Wextra -Werror

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

$(NAME): $(ALL_ARC) $(NAME_C)
	@echo "$(COLOUR_GREEN)Made main file"
	@cc $(FLAGS) -o $@ -I$(HDR_DIR) $(NAME_C) $(PSR_ARC) $(HLP_ARC)

%.a:
	@cd $(dir $@ ) && make && make clean

clean:
	@echo "$(COLOUR_YELLOW)Cleaning objects"
	@$(foreach dir,$(dir $(ALL_ARC)), cd $(dir) && make clean$(NEWLINE))

fclean: 
	@echo "$(COLOUR_YELLOW)Cleaning everything"
	@$(RM) $(NAME)
	@$(foreach dir,$(dir $(ALL_ARC)), cd $(dir) && make fclean$(NEWLINE))

re: re_libs all
	
re_libs:
	@$(foreach dir,$(dir $(ALL_ARC)), cd $(dir) && make re$(NEWLINE) )

.PHONY: all clean fclean re