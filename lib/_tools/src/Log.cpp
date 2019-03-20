/*
** EPITECH PROJECT, 2019
** Log
** File description:
** Class for create log file.
** @Author: Cédric Hennequin
** @Date:   14-03-2019 09:58:22
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 14-03-2019 11:08:03
*/

#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include "Log.hpp"

void Log::write(const std::string &str)
{
	std::time_t time = std::chrono::system_clock::to_time_t(
		std::chrono::system_clock::now()
	);
	std::ofstream file;

	if (str.empty()) {
		return;
	}
	file.open(LOG_FILE, std::fstream::out | std::ofstream::app);
	if (file.is_open()) {
		file << "Log date: " << std::ctime(&time);
		file << "- Message :" << std::endl << str << std::endl << std::endl;
		file.close();
	}
}
