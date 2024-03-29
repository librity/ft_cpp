/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 01:08:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Brain::Brain(void)
{
	std::cout << "DEBUG: Brain created: " << this << std::endl;

	int i = 0;
	while (i < Brain::power)
	{
		std::stringstream str_stream;
		str_stream << "EMPTY IDEA #" << i;
		this->ideas[i] = str_stream.str();
		i++;
	}
}

Brain::Brain(const Brain &brain)
{
	std::cout << "DEBUG: Brain copy constructor called" << std::endl;

	*this = brain;
}

Brain::~Brain(void)
{
	std::cout << "DEBUG: Brain " << this << " destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "DEBUG: Brain copy assignment operator called" << std::endl;

	if (this == &brain)
		return *this;

	int i = 0;
	while (i < Brain::power)
	{
		this->ideas[i] = brain.get_idea(i);
		i++;
	}

	return *this;
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

std::string Brain::get_idea(int index) const
{
	if (index < 0 || index > Brain::power)
		return std::string("");

	return this->ideas[index];
}

void Brain::set_idea(std::string idea, int index)
{
	if (index < 0 || index > Brain::power)
	{
		std::cout << "ERROR: Can't set idea with out-of-range index!" << std::endl;
		return;
	}

	this->ideas[index] = idea;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void Brain::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Brain: " << this << std::endl;
	std::cout << "Ideas: " << std::endl;
	int i = 0;
	while (i < Brain::power)
	{
		std::cout << "\t" + this->ideas[i] << std::endl;
		i++;
	}

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
