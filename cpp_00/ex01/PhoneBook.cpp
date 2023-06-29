/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/06/29 22:03:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_empty = true;
	this->_index = 0;
}

void PhoneBook::add_contact(std::string name, std::string phone)
{
	this->_empty = false;

	if (this->_index == 8)
		this->_index = 0;

	this->_contacts[this->_index].set(name, phone);
	this->_index++;
}

void PhoneBook::inspect(void)
{
	if (this->_empty)
	{
		std::cout << "PhoneBook empty :(" << std::endl;
		return;
	}

	int i = 0;

	std::cout << "PhoneBook contacts:" << std::endl;
	while (i < 8)
	{
		this->_contacts[i].inspect();
		i++;
	}
}
