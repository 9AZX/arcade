/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the lib ncurses.
*/

#include "NcursesModule.hpp"

extern "C" void *EntryGraph();

void *EntryGraph() { return new NcursesModule; }
