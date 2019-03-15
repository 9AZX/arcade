/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#ifndef NCURSESMODULE_HPP_
    #define NCURSESMODULE_HPP_

#include "IDisplayModule.hpp"
#include <ncurses.h>

class NcursesModule : public IDisplayModule {
	public:
		NcursesModule();
		~NcursesModule();
		void print_map(Map) override;


	protected:
	private:
};

#endif /* !NCURSESMODULE_HPP_ */
