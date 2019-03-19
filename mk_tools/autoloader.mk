##
## EPITECH PROJECT, 2019
## autoloader
## File description:
## Auto load all MK files.
##

ifeq	($(origin HEADER_AUTOLOADER_),undefined)
define	HEADER_AUTOLOADER_
endef

ifneq	($(origin CALL_FROM_MAIN),undefined)
	# Functions / header.
	include	./mk_tools/config/flags.mk
	include	./mk_tools/config/lang.mk
	include	./mk_tools/src/error.mk
	include	./mk_tools/src/tools.mk
	include	./mk_tools/src/debug.mk
	# Compilation rules.
	include	./mk_tools/src/secure.mk
	include	./mk_tools/src/vars.mk
	include	./mk_tools/src/compile.mk
	include	./mk_tools/src/symbols.mk
else ifneq	($(origin CALL_FROM_LIBS),undefined)
	# Functions / header.
	include	../mk_tools/config/flags.mk
	include	../mk_tools/config/lang.mk
	include	../mk_tools/src/error.mk
	include	../mk_tools/src/tools.mk
	include	../mk_tools/src/debug.mk
	# Compilation rules.
	include	../mk_tools/src/secure.mk
	include	../mk_tools/src/vars.mk
	include	../mk_tools/src/compile.mk
	include	../mk_tools/src/symbols.mk
else ifneq	($(origin CALL_FROM_UNIT_TESTS),undefined)
	# Functions / header.
	include	../mk_tools/config/flags.mk
	include	../mk_tools/config/lang.mk
	include	../mk_tools/src/error.mk
	include	../mk_tools/src/tools.mk
	include	../mk_tools/src/debug.mk
	# Compilation rules.
	include	../mk_tools/src/secure.mk
	include	../mk_tools/src/vars.mk
	include	../mk_tools/src/compile.mk
	include	../mk_tools/src/symbols.mk
else
	# Functions / header.
	include	../../mk_tools/config/flags.mk
	include	../../mk_tools/config/lang.mk
	include	../../mk_tools/src/error.mk
	include	../../mk_tools/src/tools.mk
	include	../../mk_tools/src/debug.mk
	# Compilation rules.
	include	../../mk_tools/src/secure.mk
	include	../../mk_tools/src/vars.mk
	include	../../mk_tools/src/compile.mk
	include	../../mk_tools/src/symbols.mk
endif

endif	# !HEADER_AUTOLOADER_
