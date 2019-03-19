/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#ifndef	NIBBLERMODULE_HPP_
#define	NIBBLERMODULE_HPP_

#include "IGameModule.hpp"

class NibblerModule : public IGameModule
{
public:
	NibblerModule() = default;
	~NibblerModule() = default;

public:
	void play() override;
	//void pause() override;
	//void endGame() override;
	//int getScore() override;
	//std::unique_ptr<Map> getMap() override;
};

#endif	/* !NIBBLERMODULE_HPP_ */
