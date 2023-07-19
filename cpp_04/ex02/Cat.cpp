/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 01:17:36 by lpaulo-m         ###   ########.fr       */
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
	this->brain = new Brain();

	std::cout << "DEBUG: Cat of type " + this->type + " created: " << this << std::endl;
}

Cat::Cat(const Cat &cat)
	: Animal()
{
	std::cout << "DEBUG: Cat copy constructor called" << std::endl;

	this->brain = new Brain(*cat.get_brain());
	*this = cat;
}

Cat::~Cat(void)
{
	delete this->brain;

	std::cout << "DEBUG: Cat " << this << " destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "DEBUG: Cat copy assignment operator called" << std::endl;

	if (this == &cat)
		return *this;

	this->type = cat.getType();
	*this->brain = *cat.get_brain();

	return *this;
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

Brain *Cat::get_brain(void) const
{
	return this->brain;
}

/******************************************************************************\
 * SETTERS
\******************************************************************************/

void Cat::set_idea(std::string idea, int index)
{
	this->brain->set_idea(idea, index);
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
