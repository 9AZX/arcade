/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the lib sfml.
*/

#include "SfmlModule.hpp"

extern "C" void *EntryGraph();

void *EntryGraph() { return new SfmlModule; }
