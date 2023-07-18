/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 18:14:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

WrongAnimal::WrongAnimal(void)
	: type("EMPTY TYPE")
{
	std::cout << "DEBUG: WrongAnimal of type " + this->type + " created: " << this << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << "DEBUG: WrongAnimal copy constructor called" << std::endl;

	*this = animal;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "DEBUG: WrongAnimal " << this << " destroyed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	std::cout << "DEBUG: WrongAnimal copy assignment operator called" << std::endl;

	if (this == &animal)
		return *this;

	this->type = animal.getType();

	return *this;
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void WrongAnimal::makeSound(void) const
{
	std::cout << "(random, savage sounds)" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void WrongAnimal::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "WrongAnimal: " << this << std::endl;
	std::cout << "Type: " << this->type << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
