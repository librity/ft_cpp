/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/09 15:23:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Contact.hpp"

class PhoneBook
{
public:
	static void run(void);

	PhoneBook(void);

private:
	int index;
	bool empty;
	static const int size = 8;
	Contact contacts[PhoneBook::size];

	void add_contact(void);
	void set_next_contact(
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret);

	void handle_search(void);
	void show_index(void);
	void show_contact_by_index(void);

	static std::string get_number(std::string field_name);
	static std::string get_text(std::string field_name);
	static bool is_digits_str(std::string str);
};

#endif
