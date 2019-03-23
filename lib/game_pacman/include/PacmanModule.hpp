/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#ifndef PACMANMODULE_HPP_
#define PACMANMODULE_HPP_

#include "ICoreModule.hpp"
#include "IGameModule.hpp"

class PacmanModule : public IGameModule {
public:
    PacmanModule() = default;
    ~PacmanModule() = default;

public:
    void play() override;
    //void pause() override;
    //void endGame() override;
    //int getScore() override;
    //std::unique_ptr<Map> getMap() override;
private:
    ICoreModule* _core;
    const GameMap _map = {
        21,
        19,
        std::vector<std::string>{
            { "###################" },
            { "#                 #" },
            { "# ## ### # ### ## #" },
            { "#                 #" },
            { "# ## # ##### # ## #" },
            { "#    #   #   #    #" },
            { "#### ### # ### ####" },
            { "   # #       # #   " },
            { "#### # ##### # ####" },
            { "       #   #       " },
            { "#### # ##### # ####" },
            { "   # #       # #   " },
            { "#### # ##### # ####" },
            { "#        #        #" },
            { "# ## ### # ### ## #" },
            { "#  #           #  #" },
            { "## # # ##### # # ##" },
            { "#    #   #   #    #" },
            { "# ###### # ###### #" },
            { "#                 #" },
            { "###################" } },
        std::map<char, struct MapBlock>{
            { '#', { "", true, BLUE } },
            { 'O', { "", false, RED } },
        }
    };
};

#endif /* !PACMANMODULE_HPP_ */
