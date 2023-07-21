/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 19:48:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Intern::Intern(void)
{
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;

	return *this;
}

Intern::~Intern()
{
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	CallbackEntry callbacks_dict[] = {
		{"presidential pardon", &Intern::makePresidentialPardonForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"shrubbery creation", &Intern::makeShrubberyCreationForm},
		{NULL, NULL}};

	CallbackEntry *entry = callbacks_dict;
	while (entry->key != NULL)
	{
		if (entry->key == form_name)
		{
			std::cout << "Intern creates " + form_name + " form." << std::endl;
			return entry->value(target);
		}

		entry++;
	}

	throw Intern::InvalidFormNameException();
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

/******************************************************************************\
 * ERRORS
\******************************************************************************/

const char *Intern::InvalidFormNameException::what(void) const throw()
{
	return "Invalid form name!";
}
