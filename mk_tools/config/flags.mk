##
## EPITECH PROJECT, 2019
## flags
## File description:
## Default compilation flags (flag(s) can be added with the var PROJECT_FLAGS).
##

ifeq	($(origin HEADER_FLAGS_),undefined)
define	HEADER_FLAGS_
endef

# C++ compilation flags.
FLAGS_CPP_DEF	=	-std=c++17	\
			-O2		\
			-Wall		\
			-Wextra

FLAGS_CPP_DEBUG	=	$(FLAGS_CPP_DEF)	\
			-g

# C compilation flags.
FLAGS_C_DEF	=	-std=c11	\
			-O2		\
			-Wall		\
			-Wextra		\
			-Werror		\
			-Wundef		\
			-Wwrite-strings	\
			-Wfloat-equal

FLAGS_C_DEBUG	=	$(FLAGS_C_DEF)	\
			-g

endif	# !HEADER_FLAGS_
