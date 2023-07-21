/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 18:51:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
	: AForm(form)
{
	*this = form;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form)
{
	if (this == &form)
		return *this;

	this->setName(form.getName());
	this->setIsSigned(form.getIsSigned());
	this->setSignGrade(form.getSignGrade());
	this->setExecGrade(form.getExecGrade());
	this->target = form.target;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->validateExecution(executor);

	std::cout << "**Vrrr**" << std::endl;
	std::cout << "**Zzzz**" << std::endl;
	std::cout << "**Buzz**" << std::endl;
	std::cout << "**Whirr**" << std::endl;

	if (RobotomyRequestForm::successfullyRobotomized())
	{
		std::cout << this->target + " successfully robotomized." << std::endl;
		return;
	}

	std::cout << "Couldn't lobotomize " + this->target + "." << std::endl;
}

bool RobotomyRequestForm::successfullyRobotomized(void)
{
	std::srand(std::time(NULL));
	int randomValue = std::rand();

	return randomValue % 2 == 1;
}
