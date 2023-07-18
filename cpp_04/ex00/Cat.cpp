/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 17:57:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Cat::Cat(void)
	: Animal()
{
	this->type = "Cat";
	std::cout << "DEBUG: Cat of type " + this->type + " created: " << this << std::endl;
}

Cat::Cat(const Cat &dog)
	: Animal()
{
	std::cout << "DEBUG: Cat copy constructor called" << std::endl;

	*this = dog;
}

Cat::~Cat(void)
{
	std::cout << "DEBUG: Cat " << this << " destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &dog)
{
	std::cout << "DEBUG: Cat copy assignment operator called" << std::endl;

	if (this == &dog)
		return *this;

	this->type = dog.getType();

	return *this;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void Cat::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Cat: " << this << std::endl;
	std::cout << "Type: " << this->type << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
