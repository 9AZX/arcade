/*
** EPITECH PROJECT, 2019
** Library
** File description:
** Library class header
** @Author: Cédric Hennequin
** @Date:   13-03-2019 11:29:35
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 25-03-2019 14:10:31
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

#if	defined(LIBRARY_PLATEFORM_FNC) && LIBRARY_PLATEFORM_FNC == 0
#	define	LIB_GAME_NIBBLER	"./games/lib_arcade_nibbler.dylib"
#	define	LIB_GAME_PACMAN		"./games/lib_arcade_pacman.dylib"
#	define	LIB_GRAPHIC_NCURSES	"./lib/lib_arcade_ncurses.dylib"
#	define	LIB_GRAPHIC_SFML	"./lib/lib_arcade_sfml.dylib"
#elif	defined(LIBRARY_PLATEFORM_FNC) && LIBRARY_PLATEFORM_FNC == 1
#	define	LIB_GAME_NIBBLER	"./games/lib_arcade_nibbler.so"
#	define	LIB_GAME_PACMAN		"./games/lib_arcade_pacman.so"
#	define	LIB_GRAPHIC_NCURSES	"./lib/lib_arcade_ncurses.so"
#	define	LIB_GRAPHIC_SFML	"./lib/lib_arcade_sfml.so"
#endif

class Library
{
public:
	Library(const std::string &path);
	~Library();

public:
	enum {
		LIB_GAME,
		LIB_GRAPHIC
	};
	bool open();
	void openNew(const std::string &path);
	void close();
	void *sym(const std::string &symbol);
	const std::string &get_path() noexcept;

protected:
	std::string _path = "";
	void *_handle = nullptr;
};

struct libs {
	int type;
	std::string name;
	std::string path;
};

#endif	/* !LIBRARY_HPP_ */
