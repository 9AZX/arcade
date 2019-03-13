/*
** EPITECH PROJECT, 2019
** Library
** File description:
** Library class header
** @Author: Cédric Hennequin
** @Date:   13-03-2019 11:29:35
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 13-03-2019 18:00:15
*/

#ifndef	LIBRARY_HPP_
#define	LIBRARY_HPP_

#include <string>
#include <dlfcn.h>
#include "Exception.hpp"

#if	!defined(LIBRARY_PLATEFORM_FNC)
#	if	defined(__APPLE__)
#		include	<TargetConditionals.h>
#		if	defined(TARGET_OS_MAC)
#			define	LIBRARY_PLATEFORM_FNC	0
#		else
#			error	"Plateform is not supported."
#		endif
#	elif	defined(__linux__)
#		define	LIBRARY_PLATEFORM_FNC	1
#	else
#		error	"Plateform is not supported."
#	endif
#endif

class Library
{
public:
	Library(const std::string &path);
	~Library();

public:
	bool open();
	void close();
	void *sym(const std::string &symbol);

protected:
	std::string _path = "";
	void *_handle = nullptr;
};

#endif	/* !LIBRARY_HPP_ */
