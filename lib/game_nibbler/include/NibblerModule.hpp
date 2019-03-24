/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#ifndef NIBBLERMODULE_HPP_
#define NIBBLERMODULE_HPP_

#include "ICoreModule.hpp"
#include "IGameModule.hpp"

class NibblerModule : public IGameModule {
 public:
  NibblerModule() = delete;
  NibblerModule(ICoreModule *core);
  ~NibblerModule() = default;

 public:
  void play() final;
  long getScore() const final;
  void pauseMenu() final;
  void endGame() final;
  const GameMap &getMap() const noexcept;

 private:
  ICoreModule *_core;
  const GameMap _map = {
      21, 19,
      std::vector<std::string>{
          {"#########################"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#                       #"}, {"#                       #"},
          {"#########################"}},
      std::map<char, struct MapBlock>{
          {'#', {"./assets/pacman/wall.png", true, CYAN, BLACK}},
          {' ', {"", false, BLACK, BLACK}},
      }};
};

#endif /* !NIBBLERMODULE_HPP_ */
