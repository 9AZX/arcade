/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#ifndef PACMANMODULE_HPP_
#define PACMANMODULE_HPP_

#include "ICoreModule.hpp"
#include "IGameModule.hpp"

class PacmanModule : public IGameModule {
 public:
  PacmanModule() = delete;
  PacmanModule(ICoreModule *);
  ~PacmanModule() = default;

 public:
  void play() final;
  void pauseMenu() final;
  void endGame() final;
  const GameMap &getMap() const noexcept;
  long getScore() const final;
  void computeInput(std::vector<enum gameInputs> keys);

 private:
  ICoreModule *_core;
  const GameMap _map = {
      21, 19,
      std::vector<std::string>{{"###################"}, {"#                 #"},
                               {"# ## ### # ### ## #"}, {"#                 #"},
                               {"# ## # ##### # ## #"}, {"#    #   #   #    #"},
                               {"#### ### # ### ####"}, {"   # #       # #   "},
                               {"#### # ## ## # ####"}, {"       #   #       "},
                               {"#### # ##### # ####"}, {"   # #       # #   "},
                               {"#### # ##### # ####"}, {"#        #        #"},
                               {"# ## ### # ### ## #"}, {"#  #           #  #"},
                               {"## # # ##### # # ##"}, {"#    #   #   #    #"},
                               {"# ###### # ###### #"}, {"#                 #"},
                               {"###################"}},
      std::map<char, struct MapBlock>{
          {'#', {"./assets/pacman/wall.png", true, BLUE, BLACK}},
          {' ', {"", false, BLACK, BLACK}},
      }};
};

#endif /* !PACMANMODULE_HPP_ */
