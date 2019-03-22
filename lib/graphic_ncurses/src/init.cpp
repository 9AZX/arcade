/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the lib ncurses.
*/

#include "NcursesModule.hpp"

extern "C" void *EntryGraph();

void *EntryGraph()
{
	// initscr();
	// ncurses.print_map(map);
	// refresh();
	// getch();
	// endwin();
	std::cout << "call (ncurses): ok" << std::endl;
	return new NcursesModule;
}
