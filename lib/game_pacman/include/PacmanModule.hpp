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
  void initPacgums();

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
  std::string musicPath = "./assets/pacman/pacman_chomp.wav";
  std::vector<std::pair<int, int>> _pacgumPos{
      {2, 2},   {3, 2},   {4, 2},   {5, 2},   {6, 2},   {7, 2},   {8, 2},
      {9, 2},   {10, 2},  {11, 2},  {12, 2},  {13, 2},  {14, 2},  {15, 2},
      {16, 2},  {17, 2},  {18, 2},  {2, 3},   {5, 3},   {9, 3},   {11, 3},
      {15, 3},  {18, 3},  {2, 4},   {3, 4},   {4, 4},   {5, 4},   {6, 4},
      {7, 4},   {8, 4},   {9, 4},   {10, 4},  {11, 4},  {12, 4},  {13, 4},
      {14, 4},  {15, 4},  {16, 4},  {17, 4},  {18, 4},  {2, 5},   {5, 5},
      {7, 5},   {13, 5},  {15, 5},  {18, 5},  {2, 6},   {3, 6},   {4, 6},
      {5, 6},   {7, 6},   {8, 6},   {9, 6},   {11, 6},  {12, 6},  {13, 6},
      {15, 6},  {16, 6},  {17, 6},  {18, 6},  {5, 7},   {15, 7},  {5, 8},
      {15, 8},  {5, 9},   {15, 9},  {5, 10},  {15, 10}, {5, 11},  {15, 11},
      {5, 12},  {15, 12}, {5, 13},  {15, 13}, {2, 14},  {3, 14},  {4, 14},
      {5, 14},  {6, 14},  {7, 14},  {8, 14},  {9, 14},  {11, 14}, {12, 14},
      {13, 14}, {14, 14}, {15, 14}, {16, 14}, {17, 14}, {18, 14}, {2, 15},
      {5, 15},  {9, 15},  {11, 15}, {15, 15}, {18, 15}, {2, 16},  {3, 16},
      {5, 16},  {6, 16},  {7, 16},  {8, 16},  {9, 16},  {10, 16}, {11, 16},
      {12, 16}, {13, 16}, {14, 16}, {15, 16}, {17, 16}, {18, 16}, {3, 17},
      {5, 17},  {7, 17},  {13, 17}, {15, 17}, {17, 17}, {2, 18},  {3, 18},
      {4, 18},  {5, 18},  {7, 18},  {8, 18},  {9, 18},  {11, 18}, {12, 18},
      {13, 18}, {15, 18}, {16, 18}, {17, 18}, {18, 18}, {2, 19},  {9, 19},
      {11, 19}, {18, 19}, {2, 20},  {3, 20},  {4, 20},  {5, 20},  {6, 20},
      {7, 20},  {8, 20},  {9, 20},  {10, 20}, {11, 20}, {12, 20}, {13, 20},
      {14, 20}, {15, 20}, {16, 20}, {17, 20}, {18, 20},
  };
  int pacgumRemain = this->_pacgumPos.size();
};
#endif /* !PACMANMODULE_HPP_ */
