/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Player
*/

#ifndef	PLAYER_HPP_
#define	PLAYER_HPP_

#include "Entity.hpp"

class Player : public AEntity
{
public:
	Player();
	~Player();

private:
	bool _move_right = false;
	bool _move_left = false;
	bool _move_up = false;
	bool _move_down = false;
};

#endif	/* !PLAYER_HPP_ */
