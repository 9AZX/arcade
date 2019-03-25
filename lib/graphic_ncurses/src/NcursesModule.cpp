/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#include "NcursesModule.hpp"

NcursesModule::NcursesModule() { initscr(); }

NcursesModule::~NcursesModule() { endwin(); }

Events NcursesModule::getInputs() {
  Events mdr;
  return mdr;
}

void NcursesModule::displayEntity(AEntity&) {}

void NcursesModule::displayMap(GameMap map) {
  for (unsigned int i = 0; i < map.grid.size(); ++i) {
    for (unsigned int idx = 0; idx < map.grid.at(i).length(); ++idx) {
      start_color();
      init_pair(1, map.blockProperties[map.grid[i].at(idx)].color,
                map.blockProperties[map.grid[i].at(idx)].colorBackground);
      attron(COLOR_PAIR(1));
      addch(map.grid[i].at(idx));
    }
    addch('\n');
  }
  refresh();
}

void NcursesModule::destructor() { delete this; }

void NcursesModule::renderTextEntity(AEntity&) const {}

void NcursesModule::renderGameEntity(AEntity&) const {}

void NcursesModule::matchInputs(Events& inputs, int key) {
  (void)inputs;
  (void)key;
}
