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
  Events getInputs() final;
  bool displayEntity(AEntity &) final;
  void displayMap(GameMap) final;
  bool renderTextEntity(AEntity &) const final;
  bool renderGameEntity(AEntity &) const final;
  void destructor() final;
  bool isOpen() const final;
  const std::string &getLibraryName() const noexcept final;
  void refreshWindow() const noexcept final;

 private:
  const std::string _name = "ncurses";
  void matchInputs(Events &inputs, int key);
};

#endif /* !NCURSESMODULE_HPP_ */
