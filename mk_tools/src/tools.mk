##
## EPITECH PROJECT, 2019
## tools
## File description:
## Tools file which contain rules for print message.
##

ifeq	($(origin HEADER_TOOLS_),undefined)
define	HEADER_TOOLS_
endef

define	message_compilation
	@printf $(1)
	@echo $(2)
endef

define	message_clean
	$(eval TMP_VAR_ := $(shell $(1)))
	printf $(DISP_STAPE)
	echo $(LANG_CLEAN1)
	@if [ -z "$(TMP_VAR_)" ]; then				\
		printf $(DISP_NO_ACTION);			\
		echo $(LANG_CLEAN3);				\
	else							\
		for file_path in $(TMP_VAR_); do		\
			printf $(DISP_DELETE_OK);		\
			echo $(LANG_CLEAN2);			\
			$(RM) "$${file_path}";			\
		done						\
	fi
endef

define	message_debug
	$(eval TMP_VAR_ := $(shell $(2)))
	printf $(DISP_STAPE)
	echo $(LANG_FCLEAN_DEBUG1)
	@if [ -z "$(TMP_VAR_)" ]; then				\
		printf $(DISP_NO_ACTION);			\
		echo $(LANG_FCLEAN_DEBUG3);			\
	else							\
		for file_path in $(TMP_VAR_); do		\
			printf $(DISP_DELETE_OK);		\
			echo $(LANG_FCLEAN_DEBUG2);		\
			$(RM) "$${file_path}";			\
		done						\
	fi
endef

define	 message_clean_header
	$(eval TMP_VAR_ := $(shell $(1)))
	@if [ "$(DISP_SILENT_MODE)" != "$(BOOL_TRUE)" ] &&		\
			[ "$(DISP_CLEAN_SILENT)" != "$(BOOL_TRUE)" ]; then\
		printf $(DISP_STAPE);					\
		echo $(LANG_FCLEAN_HEADER1); 				\
		for file in $(TMP_VAR_); do				\
			file=`basename "$${file}"`;			\
			printf $(DISP_DELETE_OK);			\
			echo $(LANG_FCLEAN_HEADER2);			\
			$(RM) $(LIB_HEADER_MOVE_TO)$${file};		\
		done							\
	else								\
		for file in $(TMP_VAR_); do				\
			file=`basename "$${file}"`;			\
			$(RM) $(LIB_HEADER_MOVE_TO)$${file};		\
		done							\
	fi
endef


# À GARDER ?????
define	check_library_is_load
	@if [ "$(findstring $(2), $(1))" = "" ]; then		\
		echo "Library $(3) not found.";			\
	else							\
		echo "Library $(3) is load for unit tests.";	\
	fi
endef

endif	# !HEADER_TOOLS_
