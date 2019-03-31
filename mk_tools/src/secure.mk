##
## EPITECH PROJECT, 2019
## secure
## File description:
## File with check for the secure mode.
##

ifeq	($(origin HEADER_SECURE_),undefined)
define	HEADER_SECURE_
endef

ifeq ($(PROJECT_SECURE_MODE),$(BOOL_TRUE))

# Detect the production environment (fedora distribution).
ifeq ($(PROJECT_AUTO_PROD),$(BOOL_TRUE))
	ifneq ("$(wildcard /etc/fedora-release)","")
		override PROJECT_PRODUCTION	=	$(BOOL_TRUE)
		override PROJECT_USE_CLANG	=	$(BOOL_FALSE)
		override DISP_DEBUGGING_MODE	=	$(BOOL_FALSE)
	endif
endif

ifeq ($(PROJECT_PRODUCTION),$(BOOL_TRUE))
	ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
		override DISP_RETURN_BLANK_LINE	=	$(BOOL_FALSE)
	endif
	PROJECT_LIB	:=	$(filter-out -lSDL2_ttf,$())
	PROJECT_LIB	:=	$(filter-out -lSDL2_image,$(PROJECT_LIB))
endif

ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
		override DISP_RETURN_BLANK_LINE	=	$(BOOL_FALSE)
	endif
endif

ifneq ($(origin CALL_FROM_SUB_MAKEFILE),undefined)
		override DISP_RETURN_BLANK_LINE	=	$(BOOL_FALSE)
endif

ifeq ($(LIB_HEADER_DIRECTORY),)
	override LIB_HEADER_DIRECTORY	=	"."
else ifeq ($(LIB_HEADER_DIRECTORY),"")
	override LIB_HEADER_DIRECTORY	=	"."
endif

# Check if terminal can support colors.
ifneq (,$(filter $(shell tput colors),8 16 88 256))
	# NTD
else
	ifeq ($(DISP_FORCE_COLOR),$(BOOL_TRUE))
		override DISP_FORCE_COLOR = $(BOOL_FALSE)
	endif
	ifeq ($(DISP_FORCE_UNICODE),$(BOOL_TRUE))
		override DISP_FORCE_UNICODE = $(BOOL_FALSE)
	endif
endif

ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
ifeq ($(DISP_CLEAN_SILENT),$(BOOL_TRUE))
	override DISP_CLEAN_SILENT	=	$(BOOL_FALSE)
endif
endif

endif	# !PROJECT_SECURE_MODE

endif	# !HEADER_SECURE_
