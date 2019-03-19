##
## EPITECH PROJECT, 2019
## pre_load
## File description:
## Include all MK files before the load operation.
##

ifeq	($(origin HEADER_PRE_LOAD_),undefined)
define	HEADER_PRE_LOAD_
endef

ifeq ($(OS),Windows_NT)
	SYSTEM_NAME	=	"Windows_NT"
	_EOF_	=	\n\r
$(error	Sorry, This plateform is not supported)
else
	SYSTEM_UNAME_S	:=	$(shell uname -s)
	SYSTEM_UNAME_M	:=	$(shell uname -m)
	_EOF_	=	\n
	ifeq ($(SYSTEM_UNAME_S),Darwin)
		SYSTEM_NAME	=	"Darwin"
	else ifeq ($(SYSTEM_UNAME_S),Linux)
		SYSTEM_NAME	=	"Linux"
	endif
endif

ifneq	($(origin CALL_FROM_MAIN),undefined)
	include	./mk_tools/config/config.mk
else ifneq	($(origin CALL_FROM_LIBS),undefined)
	include	../mk_tools/config/config.mk
else ifneq	($(origin CALL_FROM_UNIT_TESTS),undefined)
	include	../mk_tools/config/config.mk
else
	include	../../mk_tools/config/config.mk
endif

endif	# !HEADER_PRE_LOAD_
