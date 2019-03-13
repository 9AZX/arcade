/*
** EPITECH PROJECT, 2019
** Library
** File description:
** Library class (for open / close dynamic library)
** @Author: Cédric Hennequin
** @Date:   13-03-2019 11:29:05
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 13-03-2019 14:57:10
*/

#include "Library.hpp"

Library::Library(const std::string &path)
{
	this->_path = path;
}

#if	defined(LIBRARY_PLATEFORM_FNC) && LIBRARY_PLATEFORM_FNC == 0
bool Library::open(void)
{
	return (true);
}
#elif	defined(LIBRARY_PLATEFORM_FNC) && LIBRARY_PLATEFORM_FNC == 1
bool Library::open(void)
{
	return (true);
}
#else
#	error	"Include \"Library\" header or the plateform is not supported."
#endif
