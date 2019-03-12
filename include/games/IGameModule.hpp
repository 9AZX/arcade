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
		void endGame();
		char *getMap();
		int getScore();

	protected:
	private:
		char *_map;
		int _score;
};

#endif /* !IGAMEMODULE_HPP_ */
