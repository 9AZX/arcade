/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the lib sdl.
*/

#include "SdlModule.hpp"

extern "C" void *EntryGraph();

void *EntryGraph() { return new SdlModule; }
