##
## EPITECH PROJECT, 2019
## vars
## File description:
## All variables use for the compilation.
##

ifeq	($(origin HEADER_VARS_),undefined)
define	HEADER_VARS_
endef

# Choose the good message.
ifeq ($(PROJECT_PRODUCTION),$(BOOL_TRUE))
	DISP_MESSAGE_OK	=	"[ OK ] "
	DISP_DELETE_OK	=	"[ X ] "
	DISP_STAPE	=	"[ - ] "
	DISP_NO_ACTION	=	"[ * ] "
else
ifeq ($(DISP_FORCE_COLOR),$(BOOL_TRUE))
	DISP_MESSAGE_OK	=	"[ \e[32mOK\e[0m ] "
	DISP_DELETE_OK	=	"[ \e[31mX\e[0m ] "
	DISP_STAPE	=	"[ \e[33m-\e[0m ] "
	DISP_NO_ACTION	=	"[ \e[34m*\e[0m ] "
else ifeq ($(SYSTEM_NAME),Darwin && $(DISP_FORCE_UNICODE),$(BOOL_FALSE))
	DISP_MESSAGE_OK	=	"✅ "
	DISP_DELETE_OK	=	"❌ "
	DISP_STAPE	=	"⚠️  "
	DISP_NO_ACTION	=	"🌀 "
else ifeq ($(DISP_FORCE_UNICODE),$(BOOL_TRUE))
	DISP_MESSAGE_OK	=	"✅ "
	DISP_DELETE_OK	=	"❌ "
	DISP_STAPE	=	"⚠️  "
	DISP_NO_ACTION	=	"🌀 "
else
	DISP_MESSAGE_OK	=	"[ OK ] "
	DISP_DELETE_OK	=	"[ X ] "
	DISP_STAPE	=	"[ - ] "
	DISP_NO_ACTION	=	"[ * ] "
endif
endif

# Force compiler error with color.
ifeq ($(DISP_FORCE_COLOR),$(BOOL_TRUE))
	FLAGS_C_DEF	+=	-fdiagnostics-color
	FLAGS_CPP_DEF	+=	-fdiagnostics-color
endif

# Remove -Werror flag if debug mode is active.
ifeq ($(DISP_DEBUGGING_MODE),$(BOOL_TRUE))
	FLAGS_C_DEF	:=	$(filter-out -Werror,$(FLAGS_C_DEF))
	FLAGS_CPP_DEF	:=	$(filter-out -Werror,$(FLAGS_CPP_DEF))
endif

# Choose compilation rules by language.
TMP_VAR_	:=	$(PROJECT_BINARY_NAME)
ifeq ($(PROJECT_LANGUAGE),"C")
	HEADER_EXT	=	.h
	OBJ	=	$(PROJECT_SRC:.c=.o)
	ifeq ($(PROJECT_BINARY_TYPE),"STATIC")
		PROJECT_BINARY_NAME	:=	lib$(TMP_VAR_).a
		AR	=	ar rc
	else ifeq ($(PROJECT_BINARY_TYPE),"SHARED")
		ifeq ($(SYSTEM_NAME),"Darwin")
			PROJECT_BINARY_NAME	:=	lib$(TMP_VAR_).dylib
			FLAGS_C_DEF	+=	-fPIC
		else ifeq ($(SYSTEM_NAME),"Linux")
			PROJECT_BINARY_NAME	:=	lib$(TMP_VAR_).so
			FLAGS_C_DEF	+=	-fPIC
		endif
	endif
	ifeq ($(PROJECT_PRODUCTION),$(BOOL_TRUE))
		CC	=	gcc
	else ifeq ($(PROJECT_USE_CLANG),$(BOOL_TRUE))
		CC	=	clang
	else
		CC	=	gcc
	endif
	ifeq ($(DISP_DEBUGGING_MODE),$(BOOL_TRUE))
		override CFLAGS	=	$(FLAGS_C_DEBUG)
	else
		override CFLAGS	=	$(FLAGS_C_DEF)
	endif
else ifneq (,$(filter $(PROJECT_LANGUAGE),"C++" "CPP"))
	HEADER_EXT	=	.hpp
	OBJ	=	$(PROJECT_SRC:.cpp=.o)
	ifeq ($(PROJECT_BINARY_TYPE),"STATIC")
		PROJECT_BINARY_NAME	:=	lib$(TMP_VAR_).a
		AR	=	ar rc
	else ifeq ($(PROJECT_BINARY_TYPE),"SHARED")
		ifeq ($(SYSTEM_NAME),"Darwin")
			PROJECT_BINARY_NAME	:=	lib$(TMP_VAR_).dylib
			FLAGS_CPP_DEF	+=	-fPIC
		else ifeq ($(SYSTEM_NAME),"Linux")
			PROJECT_BINARY_NAME	:=	lib$(TMP_VAR_).so
			FLAGS_CPP_DEF	+=	-fPIC
		endif
	endif
	ifeq ($(PROJECT_PRODUCTION),$(BOOL_TRUE))
		CXX	=	g++
	else ifeq ($(PROJECT_USE_CLANG),$(BOOL_TRUE))
		CXX	=	clang++
	else
		CXX	=	g++
	endif
	ifeq ($(PROJECT_BINARY_TYPE),"STATIC")
		AR	=	ar rc
	endif
	ifeq ($(DISP_DEBUGGING_MODE),$(BOOL_TRUE))
		override CXXFLAGS	=	$(FLAGS_CPP_DEBUG)
	else
		override CXXFLAGS	=	$(FLAGS_CPP_DEF)
	endif
else
TMP_VAR_	:=	$(LANG_ERR_PROJECT_LANGUAGE)
$(TMP_ERR_)
endif

ifneq ($(PROJECT_LIBRARY_DIR),)
	override LDFLAGS	=	$(PROJECT_LIBRARY_DIR)
else
	override LDFLAGS	=
endif

ifneq ($(PROJECT_INCLUDE),)
	override CPPFLAGS	=	$(PROJECT_INCLUDE)
endif

ifneq ($(PROJECT_LIB),)
	override LDFLAGS	+=	$(PROJECT_LIB)
endif

endif	# !HEADER_VARS_
