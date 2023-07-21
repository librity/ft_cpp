/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 19:04:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("presidential pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("presidential pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
	: AForm(form)
{
	*this = form;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &form)
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

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->validateExecution(executor);

	std::cout << this->target + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
