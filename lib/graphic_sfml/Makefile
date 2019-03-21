##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for SFML graphic library.
##

include	../../mk_tools/pre_load.mk

PROJECT_LANGUAGE	:=	"C++"

PROJECT_BINARY_TYPE	:=	"SHARED"

PROJECT_BINARY_NAME	:=	"_arcade_sfml"

PROJECT_LIB	:=	-lncurses	\
			-lsfml-graphics	\
			-lsfml-window	\
			-lsfml-system	\
			-lsfml-audio

PROJECT_INCLUDE	:=	-I../../include/graphics/	\
			-I../../include/shared/		\
			-I./include/

PROJECT_SRC	:=	./src/SfmlModule.cpp	\
			./src/Map.cpp		\
			./src/init.cpp

LIB_BINARY_MOVE_TO	:=	"../"

include	../../mk_tools/autoloader.mk
