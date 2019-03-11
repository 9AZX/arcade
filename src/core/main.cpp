/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Main function
*/

#include <memory>
#include <iostream>
#include "Application.hpp"

void display_usage(void)
{
    std::cerr << "USAGE:\n\t./arcade [GRAPHIC LIB PATH]" << std::endl;
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        display_usage();
        return 84;
    }
    std::unique_ptr<Application> app(new Application);
    (void) **argv++;
    app->init(*argv);
    return 0;
}