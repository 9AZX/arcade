/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Class Application
*/

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <memory>
#include <string>
#include "ICoreModule.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Library.hpp"

#define ENTRY_POINT_GAME "EntryGame"
#define ENTRY_POINT_GRAPHIC "EntryGraph"

class Application : public ICoreModule {
 public:
  Application() = default;
  ~Application() = default;

 public:
  void init(const int argc, const char **argv);
  void stop();
  void open_graphical_library();
  void open_game_library();
  void switchLib(const int type, const std::string &path);
  void storeGameEntity(AEntity *entity) final;
  AEntity &getEntity(std::string name) final;
  Events getInputs() final;
  void renderAll() final;
  void setMap(GameMap &map) final;
  bool isOpen() const final;

 protected:
  std::unique_ptr<Library> _game = nullptr;
  std::unique_ptr<Library> _graphic = nullptr;
  IGameModule *_gameClass = nullptr;
  IDisplayModule *_graphClass = nullptr;
  void *(*fptr_game)(void *) = nullptr;
  void *(*fptr_graphic)() = nullptr;
};

#endif /* !APPLICATION_HPP_ */
