/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Exception
*/

#ifndef	EXCEPTION_HPP_
#define	EXCEPTION_HPP_

#include <string>
#include <exception>

class Exception : public std::exception
{
public:
	Exception() = default;
	Exception(const std::string &msg);
	~Exception() = default;

public:
	const char *what() const noexcept;

private:
	std::string _msg = "An internal error occured.";
};

#endif	/* !EXCEPTION_HPP_ */
