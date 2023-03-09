##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles mylib
##

CC 	=	gcc

SRC	=	src/main.c \
		src/check.c \
		src/error.c \
		src/free.c \
		src/game_file.c \
		src/move.c \
		src/sokoban.c

LIB 	=	lib/my/my_put.c	\
		lib/my/my_str.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	libmy.a

NAME_BIN	= 	my_sokoban

INCLUDES	=	-I includes/

LIBA		=	-L. -lmy

LNCUR 	= 	-lncurses

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all: 	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@$(CC) $(LNCUR) -o $(NAME_BIN) $(LIBA)
		@echo -e "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@find . \( -name "*~" -o -name "#*" -o -name "*#" \) -delete
	@echo -e "\033[1;31mClean done\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BIN)
	@rm -f coding-style-reports.log
	@rm -f vgcore.*
	@echo -e "\033[1;31mFclean done\033[0m"

re: 	fclean all

.PHONY: all re clean fclean
