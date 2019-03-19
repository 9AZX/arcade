##
## EPITECH PROJECT, 2019
## symbols
## File description:
## All symbols use for the compilation.
##

ifeq	($(origin HEADER_SYMBOLS_),undefined)
define	HEADER_SYMBOLS_
endef

ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
.SILENT:
endif

ifneq ($(origin CALL_FROM_LIBS),undefined)
all:	debug
	$(eval TMP_VAR_	:= $(subst /,$(space),$(sort $(dir $(wildcard */)))))
	@echo ""
	@for dir in $(TMP_VAR_); do					\
		$(MAKE) --no-print-directory -C "$${dir}"		\
			CALL_FROM_SUB_MAKEFILE=;			\
		if [ "$${dir}" != $(lastword $(TMP_VAR_)) ]; then	\
			echo "";					\
		fi							\
	done
else ifneq ($(origin CALL_FROM_MAIN),undefined)
all:	debug load_lib $(PROJECT_BINARY_NAME) compile_after
ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
	@echo ""
endif
else
all:	debug $(PROJECT_BINARY_NAME) compile_after
ifeq ($(origin CALL_FROM_MAIN),undefined)
ifeq ($(origin CALL_FROM_LIBS),undefined)
ifeq ($(origin CALL_FROM_UNIT_TESTS),undefined)
ifneq ($(LIB_BINARY_MOVE_TO),)
ifneq ($(LIB_BINARY_MOVE_TO),".")
	@mv $(PROJECT_BINARY_NAME) $(LIB_BINARY_MOVE_TO)$(PROJECT_BINARY_NAME)
endif
endif
ifneq ($(LIB_HEADER_MOVE_TO),)
ifneq ($(LIB_HEADER_MOVE_TO),".")
	@find $(LIB_HEADER_DIRECTORY)			\
		-name "*$(HEADER_EXT)"			\
		-exec cp {} $(LIB_HEADER_MOVE_TO) \;
endif
endif
endif
endif
endif
ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
	@echo ""
endif
endif

$(PROJECT_BINARY_NAME):	$(OBJ)
ifeq ($(PROJECT_BINARY_TYPE),"STATIC")
	@$(AR) $(PROJECT_BINARY_NAME) $(OBJ)
else ifeq ($(PROJECT_LANGUAGE),"C")
ifeq ($(PROJECT_BINARY_TYPE),"SHARED")
	@$(CC) -shared -o $(PROJECT_BINARY_NAME) $(OBJ) $(LDFLAGS)
else
	@$(CC) -o $(PROJECT_BINARY_NAME) $(OBJ) $(LDFLAGS)
endif
else ifneq (,$(filter $(PROJECT_LANGUAGE),"C++" "CPP"))
ifeq ($(PROJECT_BINARY_TYPE),"SHARED")
	@$(CXX) -shared -o $(PROJECT_BINARY_NAME) $(OBJ) $(LDFLAGS)
else
	@$(CXX) -o $(PROJECT_BINARY_NAME) $(OBJ) $(LDFLAGS)
endif
endif

ifneq ($(origin CALL_FROM_MAIN),undefined)
load_lib:
	@$(MAKE) --no-print-directory -C $(LIB_INDEX_PATH)	\
		CALL_FROM_SUB_MAKEFILE=
	@echo ""
endif

debug:
ifeq ($(origin CALL_FROM_SUB_MAKEFILE),undefined)
ifneq ($(MAKECMDGOALS),re)
ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
	@echo ""
endif
endif
ifeq ($(MAKECMDGOALS),re)
	@echo ""
endif
ifeq ($(DISP_DEBUGGING_MODE),$(BOOL_TRUE))
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	@echo "-- debug mode --"
else ifeq ($(PROJECT_PRODUCTION),$(BOOL_TRUE))
	@echo "-- debug mode --"
else ifeq ($(DISP_FORCE_COLOR),$(BOOL_TRUE))
	@$(call print_debug_mode_color)
else ifeq ($(DISP_FORCE_UNICODE),$(BOOL_TRUE))
	@$(call print_debug_mode_color)
else
	@$(call print_debug_mode)
endif
endif
ifeq ($(origin CALL_FROM_LIBS),undefined)
ifeq ($(origin CALL_FROM_MAIN),undefined)
	@echo ""
endif
endif
endif

ifeq ($(origin CALL_FROM_LIBS),undefined)
compile_after:
	@printf $(DISP_NO_ACTION)
	@echo $(LANG_COMPILATION_BINARY)
endif

ifneq ($(origin CALL_FROM_LIBS),undefined)
clean:
	$(eval TMP_VAR_	:= $(subst /,$(space),$(sort $(dir $(wildcard */)))))
	@for dir in $(TMP_VAR_); do					\
		$(MAKE) --no-print-directory -C "$${dir}"		\
			clean CALL_FROM_SUB_MAKEFILE=;			\
		if [ "$(DISP_SILENT_MODE)" == "$(BOOL_TRUE)" ] ||	\
			[ "$(DISP_CLEAN_SILENT)" == "$(BOOL_TRUE)" ]; then\
			echo "CLEAN ($${dir})";			\
		elif [ "$${dir}" != $(lastword $(TMP_VAR_)) ]; then	\
			echo "";					\
		fi							\
	done
else
clean:
ifneq ($(origin CALL_FROM_MAIN),undefined)
ifneq ($(MAKECMDGOALS),fclean)
ifneq ($(MAKECMDGOALS),re)
	@$(MAKE) --no-print-directory -C $(LIB_INDEX_PATH) clean	\
		CALL_FROM_SUB_MAKEFILE=
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	@echo "CLEAN (MAIN)"
else ifeq ($(DISP_CLEAN_SILENT),$(BOOL_TRUE))
	@echo "CLEAN (MAIN)"
else
	@echo ""
endif
endif
endif
endif
ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
	@echo ""
endif
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
ifneq ($(origin CALL_FROM_MAIN),undefined)
	@$(RM) $(OBJ)
else
		@find . -name "*.o" -delete
endif
else ifeq ($(DISP_CLEAN_SILENT),$(BOOL_TRUE))
ifneq ($(origin CALL_FROM_MAIN),undefined)
		@$(RM) $(OBJ)
else
		@find . -name "*.o" -delete
endif
else
ifneq ($(origin CALL_FROM_MAIN),undefined)
		@$(call message_clean,find $(PROJECT_MAIN_SRC) -name "*.o")
else
		@$(call message_clean,find . -name "*.o")
endif
endif
ifneq ($(MAKECMDGOALS),fclean)
ifneq ($(MAKECMDGOALS),re)
ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
	@echo ""
endif
endif
endif
endif

ifneq ($(origin CALL_FROM_LIBS),undefined)
fclean:
	$(eval TMP_VAR_	:= $(subst /,$(space),$(sort $(dir $(wildcard */)))))
	@for dir in $(TMP_VAR_); do					\
		$(MAKE) --no-print-directory -C "$${dir}"		\
			fclean CALL_FROM_SUB_MAKEFILE=;			\
		if [ "$(DISP_SILENT_MODE)" == "$(BOOL_TRUE)" ] ||	\
			[ "$(DISP_CLEAN_SILENT)" == "$(BOOL_TRUE)" ]; then\
			echo "FCLEAN ($${dir})";			\
		elif [ "$${dir}" != $(lastword $(TMP_VAR_)) ]; then	\
			echo "";					\
		fi							\
	done
else
fclean:	clean
ifneq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
ifneq ($(DISP_CLEAN_SILENT),$(BOOL_TRUE))
	@printf $(DISP_DELETE_OK)
	@echo $(LANG_FCLEAN_BINARY)
endif
endif
ifneq ($(origin CALL_FROM_MAIN),undefined)
	@$(RM) $(PROJECT_BINARY_NAME)
else ifeq ($(LIB_BINARY_MOVE_TO),)
	@$(RM) $(PROJECT_BINARY_NAME)
else ifeq ($(LIB_BINARY_MOVE_TO),".")
	@$(RM) $(PROJECT_BINARY_NAME)
else
	@$(RM) $(LIB_BINARY_MOVE_TO)$(PROJECT_BINARY_NAME)
endif
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	@find . -name "vgcore.*" -delete
	@find . -name "*.gcno" -delete
	@find . -name "*.gcna" -delete
else ifeq ($(DISP_CLEAN_SILENT),$(BOOL_TRUE))
	@find . -name "vgcore.*" -delete
	@find . -name "*.gcno" -delete
	@find . -name "*.gcna" -delete
else
	@$(call message_debug,\"vgcore\",find . -name "vgcore.*")
	@$(call message_debug,\"gcno\",find . -name "*.gcno")
	@$(call message_debug,\"gcna\",find . -name "*.gcna")
endif
ifeq ($(origin CALL_FROM_MAIN),undefined)
ifeq ($(origin CALL_FROM_LIBS),undefined)
ifeq ($(origin CALL_FROM_UNIT_TESTS),undefined)
ifneq ($(LIB_HEADER_MOVE_TO),)
ifneq ($(LIB_HEADER_MOVE_TO),".")
	@$(call message_clean_header,find $(LIB_HEADER_DIRECTORY) -name "*$(HEADER_EXT)")
endif
endif
endif
endif
endif
ifneq ($(origin CALL_FROM_MAIN),undefined)
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	@echo "FCLEAN (MAIN)"
else ifeq ($(DISP_CLEAN_SILENT),$(BOOL_TRUE))
	@echo "FCLEAN (MAIN)"
else
	@echo ""
endif
	@$(MAKE) --no-print-directory -C $(LIB_INDEX_PATH) fclean	\
		CALL_FROM_SUB_MAKEFILE=
endif
ifeq ($(DISP_RETURN_BLANK_LINE),$(BOOL_TRUE))
	@echo ""
endif
endif

re:	fclean all

.PHONY:	all $(PROJECT_BINARY_NAME) debug load_lib compile_after clean fclean re

endif	# !HEADER_SYMBOLS_
