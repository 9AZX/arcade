/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#ifndef NIBBLERMODULE_HPP_
#define NIBBLERMODULE_HPP_

#include "IGameModule.hpp"
#include "ICoreModule.hpp"

class NibblerModule : public IGameModule
{
  public:
	NibblerModule() = delete;
	NibblerModule(ICoreModule *core);
	~NibblerModule() = default;

	void play() final;
	//void pauseMenu() final;
	//void endGame() final;
	//long getScore() const final;
	//const GameMap &getMap() const noexcept final;

  private:
	ICoreModule *_core;
	const GameMap _map;
};

#endif /* !NIBBLERMODULE_HPP_ */
