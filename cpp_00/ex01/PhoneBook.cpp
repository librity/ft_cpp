/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/05 19:49:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::run(void)
{
	PhoneBook phone_book;

	std::string input;
	std::cout << "PhoneBook CLI" << std::endl;
	while (true)
	{
		std::cout << "Type in a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phone_book.create_contact();
			continue;
		}
		if (input == "SEARCH")
		{
			continue;
		}
		if (input == "EXIT")
			return;
	}
}

void PhoneBook::create_contact(void)
{
	std::cout << "New Contact:" << std::endl;

	std::string first_name = PhoneBook::get_text("First Name");
	std::string last_name = PhoneBook::get_text("Last Name");
	std::string nickname = PhoneBook::get_text("Nickname");
	std::string phone_number = PhoneBook::get_number("Phone Number");
	std::string darkest_secret = PhoneBook::get_text("Darkest Secret");

	this->add_contact(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret);
}

void PhoneBook::add_contact(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret)
{
	this->_empty = false;
	if (this->_index == 8)
		this->_index = 0;
	this->_contacts[this->_index].set(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret);
	this->_index++;
}

std::string PhoneBook::get_text(std::string field_name)
{
	std::string field;
	while (true)
	{
		std::cout << "\t" + field_name + ": ";
		std::getline(std::cin, field);
		if (field.size() == 0)
		{
			std::cout << "\t\t" + field_name + " can't be empty!" << std::endl;
			continue;
		}
		break;
	}
	return (field);
}

std::string PhoneBook::get_number(std::string field_name)
{
	std::string field;
	while (true)
	{
		std::cout << "\t" + field_name + ": ";
		std::getline(std::cin, field);
		if (field.size() == 0)
		{
			std::cout << "\t\t" + field_name + " can't be empty!" << std::endl;
			continue;
		}
		if (!PhoneBook::is_digits_str(field))
		{
			std::cout << "\t\t" + field_name + " can only contain digits!" << std::endl;
			continue;
		}
		break;
	}
	return (field);
}

bool PhoneBook::is_digits_str(std::string str)
{
	int i;
	int length;

	length = str.length();
	i = 0;
	while (i < length)
	{
		if (str[i] < '0')
			return (false);
		if (str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

void PhoneBook::inspect(void)
{
	int i;

	// std::right
	// std::setw
	if (this->_empty)
	{
		std::cout << "PhoneBook empty :(" << std::endl;
		return;
	}
	i = 0;
	std::cout << "PhoneBook contacts:" << std::endl;
	while (i < 8)
	{
		this->_contacts[i].inspect();
		i++;
	}
}
