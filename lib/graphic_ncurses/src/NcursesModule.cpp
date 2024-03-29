/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#include "NcursesModule.hpp"

NcursesModule::NcursesModule() {
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  refresh();
}

NcursesModule::~NcursesModule() { endwin(); }

const std::string &NcursesModule::getLibraryName() const noexcept {
  return this->_name;
}

Events NcursesModule::getInputs() {
  Events actual;
  int ch = 'a';
  halfdelay(3);

  if ((ch = getch()) != ERR) this->matchInputs(actual, ch);
  return actual;
}

bool NcursesModule::displayEntity(AEntity &entity) {
  switch (entity.getType()) {
    case AEntity::GAME:
      return renderGameEntity(entity);
      break;
    case AEntity::TEXT:
      return renderTextEntity(entity);
      break;
    default:
      return false;
  }
}

void NcursesModule::displayMap(GameMap map) {
  clear();
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
}

bool NcursesModule::isOpen() const { return true; }

void NcursesModule::destructor() { delete this; }

bool NcursesModule::renderTextEntity(AEntity &tmp) {
  TextEntity *entity = static_cast<TextEntity *>(&tmp);

  attron(COLOR_PAIR(1));

  mvprintw(entity->getPos().second - 1, entity->getPos().first - 1,
           entity->getText().c_str());
  return true;
}

bool NcursesModule::renderGameEntity(AEntity &tmp) {
  GameEntity *entity = static_cast<GameEntity *>(&tmp);

  init_pair(2, YELLOW, BLACK);
  init_pair(3, RED, BLACK);

  if (entity->assetChar == 'P')
    attron(COLOR_PAIR(3));
  else
    attron(COLOR_PAIR(2));

  mvaddch(entity->getPos().second - 1, entity->getPos().first - 1,
          entity->assetChar);
  refresh();
  return true;
}

void NcursesModule::matchInputs(Events &inputs, int key) {
  switch (key) {
    case KEY_RIGHT:
      inputs.keys.push_back(RIGHT);
      break;
    case KEY_LEFT:
      inputs.keys.push_back(LEFT);
      break;
    case KEY_DOWN:
      inputs.keys.push_back(DOWN);
      break;
    case KEY_UP:
      inputs.keys.push_back(UP);
      break;
    case 27:
      inputs.keys.push_back(ESCAPE);
      break;
    case ' ':
      inputs.keys.push_back(SPACE);
      break;
    case KEY_BACKSPACE:
      inputs.keys.push_back(BACK);
      break;
    case KEY_F(1):
      inputs.keys.push_back(ONE);
      break;
    case KEY_F(2):
      inputs.keys.push_back(TWO);
      break;
    case KEY_F(3):
      inputs.keys.push_back(THREE);
      break;
    case KEY_F(4):
      inputs.keys.push_back(FOUR);
      break;
    case KEY_F(5):
      inputs.keys.push_back(FIVE);
      break;
    default:
      if (isprint(key)) inputs.ascii += ((char)key);
      break;
  }
}

void NcursesModule::refreshWindow() const noexcept { refresh(); }
