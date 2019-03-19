##
## EPITECH PROJECT, 2019
## compile
## File description:
## Rule for compile all file ".c" (or ".cpp") to ".o" with a message.
##

ifeq	($(origin HEADER_COMPILE_),undefined)
define	HEADER_COMPILE_
endef

%.o:	%.c
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
else
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	@$(call message_compilation,$(DISP_MESSAGE_OK),$(LANG_COMPILATION_MESSAGE)$<)
endif

%.o:	%.cpp
ifeq ($(DISP_SILENT_MODE),$(BOOL_TRUE))
	@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@
else
	@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@
	@$(call message_compilation,$(DISP_MESSAGE_OK),$(LANG_COMPILATION_MESSAGE)$<)
endif

endif	# !HEADER_COMPILE_
