/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <iostream>

class IGameModule
{
  public:
	IGameModule();
	~IGameModule();

	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void endGame() = 0;
	virtual char *getMap() = 0;
	virtual int getScore() = 0;

  protected:
  private:
	char *_map;
	int _score;
};

#endif /* !IGAMEMODULE_HPP_ */
