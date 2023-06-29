/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/06/29 20:15:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string name, std::string phone)
{
	std::cout << "Contact constructor called" << std::endl;

	this->name = name;
	this->phone = phone;

	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return;
}

void Contact::inspect(void)
{
	std::cout << "Member function/method called" << std::endl;
	std::cout << "Name: " << this->name << ", Phone: " << this->phone << std::endl;
	return;
}
