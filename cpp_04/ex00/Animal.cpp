/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 17:24:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Animal::Animal(void)
	: type("EMPTY TYPE")
{
	std::cout << "DEBUG: Animal of type " + this->type + " created: " << this << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "DEBUG: Animal copy constructor called" << std::endl;

	*this = animal;
}

Animal::~Animal(void)
{
	std::cout << "DEBUG: Animal " << this << " destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "DEBUG: Animal copy assignment operator called" << std::endl;

	if (this == &animal)
		return *this;

	this->type = animal.getType();

	return *this;
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

std::string Animal::getType(void) const
{
	return this->type;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void Animal::makeSound(void) const
{
	std::cout << "(random, savage sounds)" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void Animal::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Animal: " << this << std::endl;
	std::cout << "Type: " << this->type << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
