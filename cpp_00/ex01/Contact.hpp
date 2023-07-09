/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/09 14:55:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>

class Contact
{

public:
	Contact(void);

	void set(
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret);

	void print_index_line(int index);
	void inspect(int index);

	bool is_empty(void);

private:
	bool empty;

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	static void print_cell(std::string content);
};

#endif
