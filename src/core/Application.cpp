/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Application
*/

#include "Application.hpp"
#include "Exception.hpp"

void Application::init(const int argc, const char **argv)
{
	if (argc != 2) {
		throw Exception(ERR_USAGE);
	}
}
