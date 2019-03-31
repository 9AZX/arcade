/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SdlModule
*/

#include "SdlModule.hpp"

SdlModule::SdlModule() {}

SdlModule::~SdlModule() {}

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