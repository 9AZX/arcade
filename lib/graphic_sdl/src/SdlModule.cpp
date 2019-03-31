/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SdlModule
*/

#include "SdlModule.hpp"

SdlModule::SdlModule() {}

SdlModule::~SdlModule() {}

const std::string &SdlModule::getLibraryName() const noexcept {
  return this->_name;
}

void SdlModule::destructor() { delete this; }

bool SdlModule::isOpen() const { return true; }

Events SdlModule::getInputs() {}
bool SdlModule::displayEntity(AEntity &) {}
void SdlModule::displayMap(GameMap) {}
bool SdlModule::renderTextEntity(AEntity &) {}
bool SdlModule::renderGameEntity(AEntity &) {}
void SdlModule::refreshWindow() const noexcept {}

bool SdlModule::matchInputs(std::vector<enum gameInputs> &inputs,
                            SDL_Keycode key) {}
void SdlModule::initGraphics(GameMap &) {}
void SdlModule::initGameEntity(AEntity &) {}
void SdlModule::initTextEntity(AEntity &) {}
void SdlModule::smoothlyMove(AEntity &) {}
void SdlModule::startMusic(std::string) {}