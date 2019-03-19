##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Standard Makefile for compile the project.
##

SRC_GAME_SNAKE	=	./src/games/snake/library_main.cpp	\
			./src/games/snake/SnakeModule.cpp

SRC_GAME_PACMAN	=	./src/games/pacman/library_main.cpp	\
			./src/games/pacman/PacmanModule.cpp

SRC_GRAPHIC_NCURSES	=	./src/graphics/ncurses/library_main.cpp	\
			./src/graphics/ncurses/NcursesModule.cpp					\
			./src/core/Map.cpp

SRC_GRAPHIC_SFML	=	./src/graphics/sfml/library_main.cpp	\
			./src/graphics/sfml/SfmlModule.cpp			\
			./src/core/Map.cpp

SRC_CLASS	=	./src/core/Application.cpp	\
			./src/core/Exception.cpp	\
			./src/core/Library.cpp		\
			./src/core/Log.cpp

SRC	=	$(SRC_CLASS)	\
		./src/core/main.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_GAME_SNAKE	=	$(SRC_GAME_SNAKE:.cpp=.o)

OBJ_GAME_PACMAN	=	$(SRC_GAME_PACMAN:.cpp=.o)

OBJ_GRAPHIC_NCURSES=	$(SRC_GRAPHIC_NCURSES:.cpp=.o)

OBJ_GRAPHIC_SFML	=	$(SRC_GRAPHIC_SFML:.cpp=.o)

CC	=	g++

NAME	=	arcade

GAME_SNAKE = lib_arcade_nibbler.so

GAME_PACMAN = lib_arcade_pacman.so

GRAPHIC_NCURSES = lib_arcade_ncurses.so

GRAPHIC_SFML = lib_arcade_SFML.so

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

$(GRAPHIC_NCURSES):	$(OBJ_GRAPHIC_NCURSES)
	$(CC) -shared -o $(GRAPHIC_NCURSES) $(OBJ_GRAPHIC_NCURSES) -lncurses

$(GRAPHIC_SFML):	$(OBJ_GRAPHIC_SFML)
	$(CC) -shared -o $(GRAPHIC_SFML) $(OBJ_GRAPHIC_SFML)

.SILENT:

core:	$(NAME)
	@echo "COMPILATION (CORE): OK"

games: $(GAME_SNAKE) $(GAME_PACMAN)
	@mv $(GAME_SNAKE) ./games/$(GAME_SNAKE)
	@mv $(GAME_PACMAN) ./games/$(GAME_PACMAN)
	@echo "COMPILATION (GAMES): OK"

graphicals: $(GRAPHIC_NCURSES) $(GRAPHIC_SFML)
	@mv $(GRAPHIC_NCURSES) ./lib/$(GRAPHIC_NCURSES)
	@mv $(GRAPHIC_SFML) ./lib/$(GRAPHIC_SFML)
	@echo "COMPILATION (GRAPHICALS): OK"

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_GAME_SNAKE)
	@rm -f $(OBJ_GAME_PACMAN)
	@rm -f $(OBJ_GRAPHIC_NCURSES)
	@rm -f $(OBJ_GRAPHIC_SFML)
	@echo "CLEAN: OK"

fclean:	clean
	@rm -f $(NAME)
	@rm -f ./games/$(GAME_SNAKE)
	@rm -f ./games/$(GAME_PACMAN)
	@rm -f ./lib/$(GRAPHIC_NCURSES)
	@rm -f ./lib/$(GRAPHIC_SFML)
	@echo "FCLEAN: OK"

re:	fclean all

.PHONY:	all $(NAME) $(GAME_SNAKE) $(GAME_PACMAN) core games graphicals clean fclean re
