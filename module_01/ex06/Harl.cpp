/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:18:24 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 22:50:53 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::printStr(std::string str) const
{
	std::cout << "> HARL: " << str << std::endl;
}

void Harl::debug(void)
{
	printStr("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!");
}

void Harl::info(void)
{
	printStr("I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
}

void Harl::warning(void)
{
	printStr("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.");
}

void Harl::error(void)
{
	printStr("This is unacceptable! I want to speak to the manager now.");
}

void Harl::complain(std::string level)
{
	std::string levelNames[] = {"DEBUG",
								"INFO",
								"WARNING",
								"ERROR"};
	void (Harl::*levelFunctionPointers[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levelNames[i])
		{
			(this->*levelFunctionPointers[i])();
			return;
		}
	}
}