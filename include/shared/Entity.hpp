/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>

class AEntity
{
public:
	enum EntityType
	{
		DEFAULT,
		GAME,
		TEXT
	};

public:
	AEntity() = delete;
	AEntity(std::string id) : id(id) {}
	~AEntity() = default;
	std::pair<int, int> getPos() { return _pos; };
	enum EntityType getType() const noexcept { return _type; }

public:
	const std::string id;

protected:
	std::pair<int, int> _pos;
	enum EntityType _type = DEFAULT;
};

#endif /* !ENTITY_HPP_ */
