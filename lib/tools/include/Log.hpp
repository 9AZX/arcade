/*
** EPITECH PROJECT, 2019
** Log
** File description:
** Log class header.
** @Author: Cédric Hennequin
** @Date:   14-03-2019 09:58:44
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 14-03-2019 10:50:30
*/

#ifndef	LOG_HPP_
#define	LOG_HPP_

#include <string>

#define	LOG_FILE	"core.log"

class Log
{
public:
	static void write(const std::string &str);
};

#endif	/* !LOG_HPP_ */
