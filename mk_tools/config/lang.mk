##
## EPITECH PROJECT, 2019
## lang
## File description:
## Messages use in Makefile.
##

ifeq	($(origin HEADER_LANG_),undefined)
define	HEADER_LANG_
endef

ifeq ($(LANGUAGE),"EN")

LANG_ERR_PROJECT_LANGUAGE	=	"Language chosen is not supported"

LANG_COMPILATION_MESSAGE	=	"Compile file: "

LANG_COMPILATION_BINARY	=	"The project $(PROJECT_BINARY_NAME) is compiled"

LANG_CLEAN1	=	"CLEAN/FCLEAN of $(PROJECT_BINARY_NAME)"

LANG_CLEAN2	=	"Delete source file: $${file_path}"

LANG_CLEAN3	=	"No source files found"

LANG_FCLEAN_BINARY	=	"Delete binary: $(PROJECT_BINARY_NAME)"

LANG_FCLEAN_DEBUG1	=	"Delete debug files ($(1))"

LANG_FCLEAN_DEBUG2	=	"Delete debug file: $${file_path}"

LANG_FCLEAN_DEBUG3	=	"No debug files found"

LANG_FCLEAN_HEADER1	=	"Deleting all header files"

LANG_FCLEAN_HEADER2	=	"Delete header file: $${file}"

else ifeq ($(LANGUAGE),"FR")

LANG_ERR_PROJECT_LANGUAGE	=	"Le langage choisi n'est pas supporté"

LANG_COMPILATION_MESSAGE	=	"Compilation du fichier: "

LANG_COMPILATION_BINARY	=	"Le projet $(PROJECT_BINARY_NAME) est compilé"

LANG_COMPILATION_CLEAN	=	"Suppression du fichier source : $${file_path}"

LANG_CLEAN1	=	"CLEAN/FCLEAN de $(PROJECT_BINARY_NAME)"

LANG_CLEAN2	=	"Suppression du fichier source : $${file_path}"

LANG_CLEAN3	=	"Aucun fichier source trouvé"

LANG_FCLEAN_BINARY	=	"Suppression du binaire : $(PROJECT_BINARY_NAME)"

LANG_FCLEAN_DEBUG1	=	"Suppression des fichiers de debug ($(1))"

LANG_FCLEAN_DEBUG2	=	"Suppression du fichier : $${file_path}"

LANG_FCLEAN_DEBUG3	=	"Aucun fichier de debug trouvé"

LANG_FCLEAN_HEADER1	=	"Suppression de tous les fichiers header"

LANG_FCLEAN_HEADER2	=	"Suppression du fichier header : $${file}"

else
TMP_VAR_	:=	"Output language ($(LANGUAGE)) chosen is not support"
$(TMP_ERR_)
endif

endif	# !HEADER_LANG_
