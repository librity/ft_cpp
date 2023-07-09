/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/09 15:37:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::run(void)
{
	PhoneBook phone_book;
	std::string input;

	std::cout << std::endl;
	std::cout << "/-------------\\" << std::endl;
	std::cout << "|PhoneBook CLI|" << std::endl;
	std::cout << "\\-------------/" << std::endl;
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Type in a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);

		if (input == "ADD")
		{
			phone_book.add_contact();
			continue;
		}

		if (input == "SEARCH")
		{
			phone_book.handle_search();
			continue;
		}

		if (input == "EXIT")
			return;

		std::cout << "\tInvalid command!" << std::endl;
	}
}

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->empty = true;
}

void PhoneBook::add_contact(void)
{
	std::cout << std::endl;
	std::cout << "New Contact:" << std::endl;
	std::string first_name = PhoneBook::get_text("First Name");
	std::string last_name = PhoneBook::get_text("Last Name");
	std::string nickname = PhoneBook::get_text("Nickname");
	std::string phone_number = PhoneBook::get_number("Phone Number");
	std::string darkest_secret = PhoneBook::get_text("Darkest Secret");

	this->set_next_contact(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret);
	std::cout << std::endl;
}

void PhoneBook::set_next_contact(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret)
{
	Contact *next_contact;

	this->empty = false;

	this->index = this->index % 8;
	next_contact = &this->contacts[this->index];
	next_contact->set(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret);
	this->index++;
}

void PhoneBook::handle_search(void)
{
	if (this->empty)
	{
		std::cout << "\tCan't search an empty PhoneBook!" << std::endl;
		return;
	}

	this->show_index();
	this->show_contact_by_index();
}

void PhoneBook::show_index(void)
{
	int i;

	std::cout << std::endl;
	std::cout << "/-------------------------------------------\\" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	i = 0;
	while (i < PhoneBook::size)
	{
		this->contacts[i].print_index_line(i);
		i++;
	}

	std::cout << "\\-------------------------------------------/" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::show_contact_by_index(void)
{
	std::string index_str;
	int index;
	Contact contact;

	while (true)
	{
		std::cout << "Type a valid index to display the contact: ";
		std::getline(std::cin, index_str);

		if (index_str.size() == 0)
		{
			std::cout << "\tIndex must be an integer!" << std::endl;
			continue;
		}

		if (!PhoneBook::is_digits_str(index_str))
		{
			std::cout << "\tIndex must be an integer!" << std::endl;
			continue;
		}

		index = std::atoi(index_str.c_str());
		if (index < 0 || index >= PhoneBook::size)
		{
			std::cout << "\tMust be >= 0 and < " << PhoneBook::size << "!" << std::endl;
			continue;
		}

		contact = this->contacts[index];
		if (contact.is_empty())
		{
			std::cout << "\tIndex must reference a non-empty contact!" << std::endl;
			continue;
		}

		contact.inspect(index);
		break;
	}
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
