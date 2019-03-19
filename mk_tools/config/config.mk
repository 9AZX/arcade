##
## EPITECH PROJECT, 2019
## config
## File description:
## Compilation and project parameters for all Makefiles.
##

ifeq	($(origin HEADER_CONFIG_),undefined)
define	HEADER_CONFIG_
endef

# ██╗   ██╗ █████╗ ██████╗ ███████╗
# ██║   ██║██╔══██╗██╔══██╗██╔════╝
# ██║   ██║███████║██████╔╝███████╗
# ╚██╗ ██╔╝██╔══██║██╔══██╗╚════██║
#  ╚████╔╝ ██║  ██║██║  ██║███████║
#   ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

# Boolean: FALSE
BOOL_TRUE	=	true

# Boolean: TRUE
BOOL_FALSE	=	false

# Temporary var for function execution.
TMP_VAR_	=

# Get the last shell exit value.
TMP_SHELL_VAL	=	$(.SHELLSTATUS)

# Temporary var for error.
TMP_ERR_	=	$(error $(TMP_VAR_))

# Temporary var for exit error code.
TMP_ERR_CODE_	=	84

# Suppression rule.
RM	=	rm -rf

# ██╗      █████╗ ███╗   ██╗ ██████╗
# ██║     ██╔══██╗████╗  ██║██╔════╝
# ██║     ███████║██╔██╗ ██║██║  ███╗
# ██║     ██╔══██║██║╚██╗██║██║   ██║
# ███████╗██║  ██║██║ ╚████║╚██████╔╝
# ╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝

# Makefile language.
LANGUAGE	=	"EN"

# ██████╗ ██╗███████╗██████╗
# ██╔══██╗██║██╔════╝██╔══██╗
# ██║  ██║██║███████╗██████╔╝
# ██║  ██║██║╚════██║██╔═══╝
# ██████╔╝██║███████║██║
# ╚═════╝ ╚═╝╚══════╝╚═╝

# Activation of debug mode.
DISP_DEBUGGING_MODE	=	$(BOOL_TRUE)

# Compilation information(s) isn't display.
DISP_SILENT_MODE	=	$(BOOL_FALSE)

# Not display clean/fclean prompt.
DISP_CLEAN_SILENT	=	$(BOOL_FALSE)

# Force color in terminal when is possible (priority to unicode characters).
DISP_FORCE_COLOR	=	$(BOOL_TRUE)

# Force unicode symbol in the terminal.
DISP_FORCE_UNICODE	=	$(BOOL_FALSE)

# Return a blank line before and after the make command.
DISP_RETURN_BLANK_LINE	=	$(BOOL_FALSE)

# ██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗
# ██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝
# ██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║
# ██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║
# ██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║
# ╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝

# Experimental feature for check parameters and prevent crash or bugs.
PROJECT_SECURE_MODE	=	$(BOOL_TRUE)

# Activate the production mode.
PROJECT_PRODUCTION	=	$(BOOL_FALSE)

# Auto detect the production environment.
PROJECT_AUTO_PROD	=	$(BOOL_TRUE)

# Activate Clang compiler (default: gcc).
PROJECT_USE_CLANG	=	$(BOOL_FALSE)

# Project language (C|C++|CPP).
PROJECT_LANGUAGE	=	"C"

# The binary type (BINARY|STATIC|SHARED).
PROJECT_BINARY_TYPE	=	"BINARY"

# The binary name.
PROJECT_BINARY_NAME	=	"BINARY_NAME"

# Flag for LD to find the path to libraries (example: "-Lmy_path").
PROJECT_LIBRARY_DIR	=

# Default include path (example: "-Imy_path").
PROJECT_INCLUDE	=

# Library or libraries link to binary (example: "-lname_of_my_library").
PROJECT_LIB	=

# Project source.
PROJECT_SRC	=

# Main source directory path for the main project.
PROJECT_MAIN_SRC	=	"./src"

# ██╗     ██╗██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗
# ██║     ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
# ██║     ██║██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝
# ██║     ██║██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝
# ███████╗██║██████╔╝██║  ██║██║  ██║██║  ██║   ██║
# ╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝

# Library index path.
LIB_INDEX_PATH	=	"./lib/"

# Path for move the library after the compilation.
LIB_BINARY_MOVE_TO	=	"../../build/"

# Path for move header(s) after the compilation.
LIB_HEADER_MOVE_TO	=	"../../build/include/"

# Header directory where copied header(s).
LIB_HEADER_DIRECTORY	=	"./include"

endif	# !HEADER_CONFIG_
