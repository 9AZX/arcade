/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ICoreModule
*/

#ifndef ICOREMODULE_HPP_
#define ICOREMODULE_HPP_

#include <vector>
#include "Entity.hpp"

class ICoreModule
{
  public:
	ICoreModule();
	virtual ~ICoreModule() = default;

	// virtual void storeGameEntity(AEntity *entity) = 0;
	// virtual AEntity &getEntity(std::string name) = 0;
	// virtual std::vector<enum gameInputs> getInputs() = 0;
	// virtual void renderAll() = 0;

  protected:
  private:
};

#endif /* !ICOREMODULE_HPP_ */
