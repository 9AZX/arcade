/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IRender
*/

#ifndef IRENDER_HPP_
#define IRENDER_HPP_

#include "Entity.hpp"

class IRender
{
  public:
	virtual void renderTextEntity(AEntity &) const = 0;
	virtual void renderGameEntity(AEntity &) const = 0;
};

#endif /* !IRENDER_HPP_ */
