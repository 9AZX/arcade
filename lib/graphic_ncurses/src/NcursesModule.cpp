/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#include "NcursesModule.hpp"

NcursesModule::NcursesModule()
{
    initscr();
    refresh();
    getch();
    endwin();
}

NcursesModule::~NcursesModule()
{
    //
}

std::vector<enum gameInputs> NcursesModule::getInputs()
{
    std::vector<enum gameInputs> mdr;
    return mdr;
}

void NcursesModule::displayEntity(AEntity&)
{
}

void NcursesModule::displayMap(GameMap map)
{
}

void NcursesModule::renderTextEntity(AEntity&) const
{
}

void NcursesModule::renderGameEntity(AEntity&) const
{
}

void NcursesModule::matchInputs(std::vector<enum gameInputs>& inputs, int key)
{
    (void)inputs;
    (void)key;
}

void NcursesModule::destructor()
{
    delete this;
}
