/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include "Map.hpp"
#include <iostream>

class IDisplayModule
{
  public:
	IDisplayModule();
	~IDisplayModule();
  virtual void initScreen() = 0;
	virtual void print_map(Map) = 0;

  protected:
  private:
};

#endif /* !IDISPLAYMODULE_HPP_ */
