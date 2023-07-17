/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/17 11:20:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	CallbackEntry callbacks_dict[] = {
		{"DEBUG", static_cast<void (Harl::*)()>(&Harl::debug)},
		{"INFO", static_cast<void (Harl::*)()>(&Harl::info)},
		{"WARNING", static_cast<void (Harl::*)()>(&Harl::warning)},
		{"ERROR", static_cast<void (Harl::*)()>(&Harl::error)},
		{NULL, NULL}};

	CallbackEntry *entry = callbacks_dict;
	while (entry->key != NULL)
	{
		if (entry->key == level)
		{
			(this->*(entry->value))();
			return;
		}

		entry++;
	}

	std::cout << "Invalid complaint level: " << level << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
