/*
** EPITECH PROJECT, 2019
** SDLModule
** File description:
** SDL main renderer class
*/

#ifndef SDL_MODULE_HPP_
#define SDL_MODULE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "IDisplayModule.hpp"
#include "IRender.hpp"
#include "Inputs.hpp"

class SdlModule : public IDisplayModule, public IRender {
 public:
  SdlModule();
  virtual ~SdlModule();

  Events getInputs() final;
  void destructor() final;
  bool isOpen() const final;
  bool displayEntity(AEntity &) final;
  void displayMap(GameMap) final;
  bool renderTextEntity(AEntity &) final;
  bool renderGameEntity(AEntity &) final;
  void refreshWindow() const noexcept final;
  const std::string &getLibraryName() const noexcept final;
  void startMusic(std::string) final;

 private:
  const std::string _name = "sdl";
  bool matchInputs(std::vector<enum gameInputs> &inputs, SDL_Keycode key);
  void initGraphics(GameMap &);
  void initGameEntity(AEntity &);
  void initTextEntity(AEntity &);
  void smoothlyMove(AEntity &);
  GameMap *_map;
  std::unordered_map<int, SDL_Texture *> _sprites;
  SDL_Window *_window;
  SDL_Renderer *_renderer;
  SDL_Surface *_screen;
  TTF_Font *_default_font;
  SDL_Color WHITE = {255, 255, 255, 255};
};

#endif /* ifndef SDL_MODULE_HPP_ */
