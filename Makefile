##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Standard Makefile configuration.
##

define	CALL_FROM_MAIN
endef

include	./mk_tools/pre_load.mk

PROJECT_LANGUAGE	:=	"C++"

PROJECT_BINARY_TYPE	:=	"BINARY"

PROJECT_BINARY_NAME	:=	"arcade"

PROJECT_LIBRARY_DIR	:=	-L./build/

PROJECT_LIB	:=	-lncurses -ldl -ltools

PROJECT_INCLUDE	:=	-I./build/include/	\
			-I./include/games/	\
			-I./include/graphics	\
			-I./include/shared	\
			-I./include/

PROJECT_SRC	:=	./src/Application.cpp	\
			./src/Choose.cpp	\
			./src/Library.cpp	\
			./src/main.cpp

include	./mk_tools/autoloader.mk
