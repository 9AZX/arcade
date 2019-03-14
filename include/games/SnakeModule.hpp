/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#ifndef	SNAKEMODULE_HPP_
#define	SNAKEMODULE_HPP_

#include "IGameModule.hpp"

class SnakeModule : public IGameModule
{
public:
	SnakeModule() = default;
	~SnakeModule() = default;

public:
	void play() override;
	//void pause() override;
	//void endGame() override;
	//int getScore() override;
	//std::unique_ptr<Map> getMap() override;
};

#endif	/* !SNAKEMODULE_HPP_ */
