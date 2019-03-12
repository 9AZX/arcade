##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Standard Makefile for compile the project.
##

SRC_GAME_SNAKE	=	./src/games/snake/test.cpp

SRC_CLASS	=	./src/core/Application.cpp	\
			./src/core/Exception.cpp

SRC	=	$(SRC_CLASS)	\
		./src/core/main.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_GAME_SNAKE	=	$(SRC_GAME_SNAKE:.cpp=.o)

CC	=	g++

NAME	=	arcade

GAME_SNAKE	=	lib_arcade_snake.so

CPPFLAGS	=	-I./include/core/	\
			-I./include/games/	\
			-I./include/graphics/

CXXFLAGS	=	-std=c++17 -Wall -Wextra -Werror

all:	core games graphicals

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(GAME_SNAKE):	$(OBJ_GAME_SNAKE)
	$(CC) -shared -fPIC -o $(GAME_SNAKE) $(OBJ_GAME_SNAKE)

.SILENT:

core:	$(NAME)
	@echo "COMPILATION (CORE): OK"

games:	$(GAME_SNAKE)
	@mv $(GAME_SNAKE) ./games/$(GAME_SNAKE)
	@echo "COMPILATION (GAMES): OK"

graphicals:
	@echo "COMPILATION (GRAPHICALS): OK"

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_GAME_SNAKE)
	@echo "CLEAN: OK"

fclean:	clean
	@rm -f $(NAME)
	@rm -f ./games/$(GAME_SNAKE)
	@echo "FCLEAN: OK"

re:	fclean all

.PHONY:	all $(NAME) $(GAME_SNAKE) core games graphicals clean fclean re
