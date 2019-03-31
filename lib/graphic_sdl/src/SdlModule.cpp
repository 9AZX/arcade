/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SdlModule
*/

#include "SdlModule.hpp"

SdlModule::SdlModule() {
  if (SDL_Init(SDL_INIT_VIDEO)) throw;
  if (TTF_Init() < 0) throw;
  _font = TTF_OpenFont("./assets/retro.ttf", 18);
  if (!_font) throw;
  _window =
      SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       780, 650, SDL_WINDOW_SHOWN);
  if (_window == NULL) throw;
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  _renderer = SDL_CreateRenderer(_window, -1, 0);
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
  SDL_RenderClear(_renderer);
  SDL_RenderPresent(_renderer);
  _screen = SDL_GetWindowSurface(_window);
}

SdlModule::~SdlModule() {
  SDL_DestroyWindow(_window);
  TTF_CloseFont(_font);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

const std::string &SdlModule::getLibraryName() const noexcept {
  return this->_name;
}

void SdlModule::destructor() { delete this; }

bool SdlModule::isOpen() const { return true; }

Events SdlModule::getInputs() {
  Events events;
  return events;
}

bool SdlModule::displayEntity(AEntity &entity) {
  switch (entity.getType()) {
    case AEntity::GAME:
      return this->renderGameEntity(entity);
    case AEntity::TEXT:
      return this->renderTextEntity(entity);
    default:
      return false;
  }
}
void SdlModule::displayMap(GameMap) {}
bool SdlModule::renderTextEntity(AEntity &) { return true; }
bool SdlModule::renderGameEntity(AEntity &) { return true; }

void SdlModule::refreshWindow() const noexcept {
  SDL_RenderPresent(_renderer);
  SDL_RenderClear(_renderer);
  SDL_UpdateWindowSurface(_window);
}

bool SdlModule::matchInputs(std::vector<enum gameInputs> &, SDL_Keycode) {
  return true;
}
void SdlModule::initGraphics(GameMap &) {}
void SdlModule::initGameEntity(AEntity &) {}
void SdlModule::initTextEntity(AEntity &) {}
void SdlModule::smoothlyMove(AEntity &) {}
void SdlModule::startMusic(std::string) {}