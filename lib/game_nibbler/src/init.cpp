/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the game Pacman.
*/

#include "NibblerModule.hpp"

extern "C" void *EntryGame(ICoreModule *);

void *EntryGame(ICoreModule *core) { return new NibblerModule(core); }
