/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
    #define EXCEPTION_HPP_

#include <iostream>
#include <string>

class Exception {
	public:
		Exception();
		~Exception() = default;

	protected:
	private:
        const std::string& _msg;
};

#endif /* !EXCEPTION_HPP_ */
