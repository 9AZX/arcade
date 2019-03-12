/*
** EPITECH PROJECT, 2019
** Exception
** File description:
** Class for launch generic exception.
** @Author: Cédric Hennequin
** @Date:   04-02-2019 12:28:38
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 12-03-2019 15:36:34
*/

#include "Exception.hpp"

Exception::Exception(const std::string &msg)
{
	this->_msg = msg;
}

const char *Exception::what() const noexcept
{
	return this->_msg.c_str();
}
