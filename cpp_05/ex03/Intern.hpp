/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 19:47:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{

public:
	Intern(void);
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);
	~Intern(void);

	AForm *makeForm(std::string form_name, std::string target);

	class InvalidFormNameException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	static AForm *makePresidentialPardonForm(std::string target);
	static AForm *makeRobotomyRequestForm(std::string target);
	static AForm *makeShrubberyCreationForm(std::string target);
};

struct CallbackEntry
{
	const char *key;
	AForm *(*value)(std::string);
};

#endif
