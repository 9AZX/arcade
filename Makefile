##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Standard Makefile for compile the project.
##

SRC_GAME_SNAKE	=	./src/games/snake/entry.cpp		\
			./src/games/snake/SnakeModule.cpp

SRC_GAME_PACMAN	=	./src/games/pacman/entry.cpp		\
			./src/games/pacman/PacmanModule.cpp

SRC_CLASS	=	./src/core/Application.cpp	\
			./src/core/Exception.cpp	\
			./src/core/Library.cpp

SRC	=	$(SRC_CLASS)	\
		./src/core/main.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_GAME_SNAKE	=	$(SRC_GAME_SNAKE:.cpp=.o)

OBJ_GAME_PACMAN	=	$(SRC_GAME_PACMAN:.cpp=.o)

CC	=	g++

NAME	=	arcade

GAME_SNAKE = lib_arcade_nibbler.so

GAME_PACMAN = lib_arcade_pacman.so

CPPFLAGS	=	-I./include/shared/	\
			-I./include/core/	\
			-I./include/games/	\
			-I./include/graphics/

CXXFLAGS	=	-std=c++17 -Wall -Wextra -fPIC

all:	core games graphicals

%.o:	%.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
	@echo "- Compilation of file: $<"

$(NAME):	$(OBJ)
	$(CC) -rdynamic -o $(NAME) $(OBJ) -ldl

$(GAME_SNAKE):	$(OBJ_GAME_SNAKE)
	$(CC) -shared -o $(GAME_SNAKE) $(OBJ_GAME_SNAKE)

$(GAME_PACMAN):	$(OBJ_GAME_PACMAN)
	$(CC) -shared -o $(GAME_PACMAN) $(OBJ_GAME_PACMAN)

.SILENT:

core:	$(NAME)
	@echo "COMPILATION (CORE): OK"

games: $(GAME_SNAKE) $(GAME_PACMAN)
	@mv $(GAME_SNAKE) ./games/$(GAME_SNAKE)
	@mv $(GAME_PACMAN) ./games/$(GAME_PACMAN)
	@echo "COMPILATION (GAMES): OK"

graphicals:
	@echo "COMPILATION (GRAPHICALS): OK"

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_GAME_SNAKE)
	@rm -f $(OBJ_GAME_PACMAN)
	@echo "CLEAN: OK"

fclean:	clean
	@rm -f $(NAME)
	@rm -f ./games/$(GAME_SNAKE)
	@rm -f ./games/$(GAME_PACMAN)
	@echo "FCLEAN: OK"

re:	fclean all

.PHONY:	all $(NAME) $(GAME_SNAKE) $(GAME_PACMAN) core games graphicals clean fclean re
