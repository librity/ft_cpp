/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/09 15:30:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->empty = true;
}

void Contact::print_index_line(int index)
{
	if (this->empty)
		return;

	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << index << "|";
	Contact::print_cell(this->first_name);
	Contact::print_cell(this->last_name);
	Contact::print_cell(this->nickname);
	std::cout << std::endl;
}

void Contact::print_cell(std::string content)
{
	if (content.size() > 10)
	{
		content = content.substr(0, 10);
		content[9] = '.';
	}

	std::cout << std::setw(10);
	std::cout << content << "|";
}

void Contact::inspect(int index)
{
	if (this->empty)
		return;

	std::cout << std::endl;
	std::cout << "Contact #" << index << ":" << std::endl;
	std::cout << "\tFirst Name: " << this->first_name << std::endl;
	std::cout << "\tLast Name: " << this->last_name << std::endl;
	std::cout << "\tNickname: " << this->nickname << std::endl;
	std::cout << "\tPhone Number: " << this->phone_number << std::endl;
	std::cout << "\tDarkest Secret: " << this->darkest_secret << std::endl;
	std::cout << std::endl;
}

void Contact::set(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret)
{
	this->empty = false;

	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

bool Contact::is_empty(void)
{
	return this->empty;
}
