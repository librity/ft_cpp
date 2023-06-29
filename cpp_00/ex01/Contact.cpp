/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/06/29 22:02:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_empty = true;
}
Contact::~Contact(void) {}

void Contact::set(std::string name, std::string phone)
{
	this->_empty = false;

	this->_name = name;
	this->_phone = phone;
}

void Contact::inspect(void)
{
	if (this->_empty)
		return;

	std::cout << "\tName: " << this->_name << ", Phone: " << this->_phone << std::endl;
}
