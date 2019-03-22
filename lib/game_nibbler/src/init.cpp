/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the game Pacman.
** @Author: Cédric Hennequin
** @Date:   13-03-2019 18:24:26
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 13-03-2019 18:26:01
*/

#include "NibblerModule.hpp"

extern "C" std::unique_ptr<IGameModule> EntryGame();

std::unique_ptr<IGameModule> EntryGame()
{
	std::cout << "call (snake): ok" << std::endl;
	return nullptr;
}
