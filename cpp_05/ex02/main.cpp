/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 18:57:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// AForm a;
	// Can't instantiate an abstract class

	Bureaucrat junior("Junior Bcrat", 150);
	Bureaucrat senior("Senior Bcrat", 1);

	std::cout << std::endl;
	PresidentialPardonForm pardon("Octave");
	junior.executeForm(pardon);
	senior.signForm(pardon);
	junior.executeForm(pardon);
	senior.executeForm(pardon);
	std::cout << std::endl;

	RobotomyRequestForm roboto("Robin");
	junior.executeForm(roboto);
	senior.signForm(roboto);
	junior.executeForm(roboto);
	senior.executeForm(roboto);
	std::cout << std::endl;

	ShrubberyCreationForm park("park");
	junior.executeForm(park);
	senior.signForm(park);
	junior.executeForm(park);
	senior.executeForm(park);
	std::cout << std::endl;

	return 0;
}
