##
## EPITECH PROJECT, 2019
## cpp_d13_2018
## File description:
## Makefile
##

SRC		=	main.cpp


NAME	=	unit_tests

CXX	=	g++

INCLUDE	=	-I../include/

CXXFLAGS	=	$(INCLUDE) -Wall -fprofile-arcs -ftest-coverage -fPIC

LDFLAGS = --coverage -lcriterion 

OBJ = $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo "COMPILATION: OK"

.SILENT:

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@echo "CLEAN: OK"

fclean:	clean
	@rm -f $(NAME)
	@echo "FCLEAN: OK"

re:	fclean all

.PHONY:	all clean fclean re
