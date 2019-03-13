/*
** EPITECH PROJECT, 2019
** Library
** File description:
** Library class (for open / close dynamic library)
** @Author: Cédric Hennequin
** @Date:   13-03-2019 11:29:05
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 13-03-2019 16:25:07
*/

#include "Library.hpp"

Library::Library(const std::string &path)
{
	this->_path = path;
}

Library::~Library()
{
	try {
		this->close();
	}
	catch (...) {
		throw;
	}
}

#if	defined(LIBRARY_PLATEFORM_FNC) && LIBRARY_PLATEFORM_FNC == 0
bool Library::open()
{
	if (this->_path.empty()) {
		return false;
	}
	else if (!dlopen_preflight(this->_path.c_str())) {
		throw Exception(dlerror());
	}
	this->_handle = dlopen(this->_path.c_str(), RTLD_LAZY);
	if (!this->_handle) {
		throw Exception(dlerror());
	}
	return true;
}
#elif	defined(LIBRARY_PLATEFORM_FNC) && LIBRARY_PLATEFORM_FNC == 1
bool Library::open()
{
	if (this->_path.empty()) {
		return false;
	}
	this->_handle = dlopen(this->_path.c_str(), RTLD_LAZY);
	if (!this->_handle) {
		throw Exception(dlerror());
	}
	return true;
}
#else
#	error	"Include \"Library\" header or the plateform is not supported."
#endif

void Library::close()
{
	if (!this->_handle) {
		return;
	}
	if (this->_handle && dlclose(this->_handle) == -1) {
		throw Exception(dlerror());
	}
}
