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
  void destructor() final;
  void pauseMenu() final;
  void endGame() final;
  const GameMap &getMap() const noexcept;
  long getScore() const final;
  void computeInput(std::vector<enum gameInputs> keys);
  bool checkCollision(std::pair<int, int> nextPos) final;
  void checkApple();
  std::string getMusicPath() final { return musicPath; };
  const std::string &getLibraryName() const noexcept final {
    return this->_name;
  };

 private:
  const std::string _name = "pacman";
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
  std::string musicPath = "./assets/pacman/pacman_chomp.wav";
  int pacgumRemain = 1;
};

#endif /* !PACMANMODULE_HPP_ */
