/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 19:50:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

	Bureaucrat junior("Junior Bcrat", 150);
	Bureaucrat senior("Senior Bcrat", 1);
	Intern anon;
	std::cout << std::endl;

	AForm *pardon = anon.makeForm("presidential pardon", "Octave");
	junior.executeForm(*pardon);
	senior.signForm(*pardon);
	junior.executeForm(*pardon);
	senior.executeForm(*pardon);
	delete pardon;
	std::cout << std::endl;

	AForm *roboto = anon.makeForm("robotomy request", "Robin");
	junior.executeForm(*roboto);
	senior.signForm(*roboto);
	junior.executeForm(*roboto);
	senior.executeForm(*roboto);
	delete roboto;
	std::cout << std::endl;

	AForm *park = anon.makeForm("shrubbery creation", "park");
	junior.executeForm(*park);
	senior.signForm(*park);
	junior.executeForm(*park);
	senior.executeForm(*park);
	delete park;
	std::cout << std::endl;

	try
	{
		anon.makeForm("badbad", "park");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
