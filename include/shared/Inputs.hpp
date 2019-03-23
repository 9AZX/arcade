/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Inputs
*/

#ifndef INPUTS_HPP_
#define INPUTS_HPP_

#include <iostream>
#include <vector>

enum gameInputs {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    ESCAPE,
    ENTER,
    BACK,
    EXIT,
    SPACE
};

struct Events {
    std::vector<enum gameInputs> keys;
    std::string ascii;
};

typedef struct Events Events;

#endif /* !INPUTS_HPP_ */
