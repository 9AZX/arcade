##
## EPITECH PROJECT, 2019
## error
## File description:
## Function for print an error.
##

ifndef	HEADER_ERROR_
define	HEADER_ERROR_
endef

define	exception
	@echo "Error: $(1)"
	@exit $(TMP_ERR_CODE_)
endef

endif	# !HEADER_ERROR_
