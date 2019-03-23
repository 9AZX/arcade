/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the game Pacman.
** @Author: Cédric Hennequin
** @Date:   13-03-2019 18:24:26
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 13-03-2019 18:25:15
*/

#include "PacmanModule.hpp"

extern "C" void *EntryGame(ICoreModule *);

void *EntryGame(ICoreModule *core) { return new PacmanModule(core); }
