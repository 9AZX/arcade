/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
    #define IGAMEMODULE_HPP_

class IGameModule {
	public:
		IGameModule();
		~IGameModule();

        void play();
        void pause();
        void end_game();
	protected:
	private:
};

#endif /* !IGAMEMODULE_HPP_ */
