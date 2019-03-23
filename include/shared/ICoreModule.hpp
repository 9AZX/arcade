/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ICoreModule
*/

#ifndef ICOREMODULE_HPP_
#define ICOREMODULE_HPP_

#include "Entity.hpp"
#include "GameMap.hpp"
#include "Inputs.hpp"
#include <vector>

class ICoreModule {
public:
    virtual ~ICoreModule() = default;
    virtual void storeGameEntity(AEntity* entity) = 0;
    virtual AEntity& getEntity(std::string name) = 0;
    virtual std::vector<enum gameInputs> getInputs() = 0;
    virtual void renderAll() = 0;
    virtual void setMap(GameMap& map);

protected:
private:
};

#endif /* !ICOREMODULE_HPP_ */
