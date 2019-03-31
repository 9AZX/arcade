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

  void play() final;
  long getScore() const final;
  void pauseMenu() final;
  void destructor() final;
  void endGame() final;
  const GameMap &getMap() const noexcept;
  bool checkCollision(std::pair<int, int> nextPos) final;
  void computeInput(std::vector<enum gameInputs> keys);
  std::string getMusicPath() final { return musicPath; };
  const std::string &getLibraryName() const noexcept final {
    return this->_name;
  };

 private:
  const std::string _name = "nibbler";
  ICoreModule *_core;
  const GameMap _map = {
      19, 19,
      std::vector<std::string>{{"###################"},
                               {"#                 #"},
                               {"# ### # ### # ### #"},
                               {"# # # #     # # # #"},
                               {"# ### # # # # ### #"},
                               {"#     # # # #     #"},
                               {"# ##### # # ##### #"},
                               {"# #             # #"},
                               {"# # ##### ##### # #"},
                               {"#                 #"},
                               {"# ##### ### ##### #"},
                               {"#       # #       #"},
                               {"# ### # ### # ### #"},
                               {"# # # #     # # # #"},
                               {"# ### # ### # ### #"},
                               {"#     # # # #     #"},
                               {"# ##### ### ##### #"},
                               {"#                 #"},
                               {"###################"}},
      std::map<char, struct MapBlock>{
          {'#', {"./assets/pacman/wall.png", true, CYAN, BLACK}},
          {' ', {"", false, BLACK, BLACK}},
      }};
  unsigned int snakeWidth = 1;
  unsigned int appleRemain = 6;
  void checkApple();
  void bodyMove();
  void forward();
  void resetPos();
  void makeMove(std::pair<int, int>);
  void eatTail();
  std::string musicPath = "./assets/nibbler/theme-music.wav";
};

#endif /* !NIBBLERMODULE_HPP_ */