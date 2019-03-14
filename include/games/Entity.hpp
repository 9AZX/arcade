/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

#include <SFML/Graphics.hpp>

class Entity {
	public:
		Entity();
		~Entity();

	protected:
        sf::Vector2f _pos;
        bool _isAlive;
        std::string _assets_sprite;
        char _ncurses_sprite;
	private:
};

#endif /* !ENTITY_HPP_ */
