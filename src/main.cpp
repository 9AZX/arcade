/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Main function
*/

#include <iostream>
#include <memory>
#include "Application.hpp"
#include "Exception.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		std::unique_ptr<Application> app(new Application);
		app->init(argc, argv);
		app->stop();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return 84;
	}
	catch (const Exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 84;
	}
	catch (...)
	{
		std::cerr << "An internal error occured." << std::endl;
		return 84;
	}
	return 0;
}
