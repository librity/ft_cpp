/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 18:19:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

WrongCat::WrongCat(void)
	: WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "DEBUG: WrongCat of type " + this->type + " created: " << this << std::endl;
}

WrongCat::WrongCat(const WrongCat &dog)
	: WrongAnimal()
{
	std::cout << "DEBUG: WrongCat copy constructor called" << std::endl;

	*this = dog;
}

WrongCat::~WrongCat(void)
{
	std::cout << "DEBUG: WrongCat " << this << " destroyed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &dog)
{
	std::cout << "DEBUG: WrongCat copy assignment operator called" << std::endl;

	if (this == &dog)
		return *this;

	this->type = dog.getType();

	return *this;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void WrongCat::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "WrongCat: " << this << std::endl;
	std::cout << "Type: " << this->type << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
