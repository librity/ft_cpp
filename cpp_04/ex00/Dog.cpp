/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 17:31:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Dog::Dog(void)
	: Animal()
{
	this->type = "Dog";
	std::cout << "DEBUG: Dog of type " + this->type + " created: " << this << std::endl;
}

Dog::Dog(const Dog &dog)
	: Animal()
{
	std::cout << "DEBUG: Dog copy constructor called" << std::endl;

	*this = dog;
}

Dog::~Dog(void)
{
	std::cout << "DEBUG: Dog " << this << " destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "DEBUG: Dog copy assignment operator called" << std::endl;

	if (this == &dog)
		return *this;

	this->type = dog.getType();

	return *this;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void Dog::makeSound(void) const
{
	std::cout << "Wooof!" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void Dog::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Dog: " << this << std::endl;
	std::cout << "Type: " << this->type << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
