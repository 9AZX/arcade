/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Exception
*/

#include "Exception.hpp"

Exception::Exception(const std::string &msg) : _msg(msg)
{}

const char *Exception::what() const noexcept
{
    return this->_msg.c_str();
}