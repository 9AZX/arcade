/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#ifndef NCURSESMODULE_HPP_
#define NCURSESMODULE_HPP_

#include <ncurses.h>
#include <memory>
#include <vector>
#include "IDisplayModule.hpp"
#include "IRender.hpp"

class NcursesModule : public IDisplayModule, public IRender {
 public:
  NcursesModule();
  virtual ~NcursesModule();

 public:
  std::vector<enum gameInputs> getInputs() final;
  void displayEntity(AEntity &) final;
  void displayMap(GameMap) final;
  void renderTextEntity(AEntity &) const final;
  void renderGameEntity(AEntity &) const final;
  void destructor() final;
  bool isOpen() const final;

 private:
  void matchInputs(std::vector<enum gameInputs> &inputs, int key);
};

#endif /* !NCURSESMODULE_HPP_ */
