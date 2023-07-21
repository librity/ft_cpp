/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 17:25:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

AForm::AForm(void)
	: target(""), name(""), isSigned(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: target(""), name(name), isSigned(false), signGrade(150), execGrade(150)
{
	this->setSignGrade(signGrade);
	this->setExecGrade(execGrade);
}

AForm::AForm(const AForm &form)
	: target(""), name(""), isSigned(false), signGrade(150), execGrade(150)
{
	*this = form;
}

AForm &AForm::operator=(const AForm &form)
{
	if (this == &form)
		return *this;

	this->setName(form.name);
	this->setIsSigned(form.isSigned);
	this->setSignGrade(form.signGrade);
	this->setExecGrade(form.execGrade);
	this->target = form.target;

	return *this;
}

AForm::~AForm()
{
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

const std::string &AForm::getName(void) const
{
	return this->name;
}

bool AForm::getIsSigned(void) const
{
	return this->isSigned;
}

int AForm::getSignGrade(void) const
{

	return this->signGrade;
}

int AForm::getExecGrade(void) const
{
	return this->execGrade;
}

const std::string &AForm::getTarget(void) const
{
	return this->target;
}

/******************************************************************************\
 * SETTERS
\******************************************************************************/

void AForm::setName(std::string name)
{
	const_cast<std::string &>(this->name) = name;
}

void AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void AForm::setSignGrade(int newGrade)
{
	AForm::validateGrade(newGrade);

	const_cast<int &>(this->signGrade) = newGrade;
}

void AForm::setExecGrade(int newGrade)
{
	AForm::validateGrade(newGrade);

	const_cast<int &>(this->execGrade) = newGrade;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void AForm::beSigned(const Bureaucrat &bcrat)
{
	if (bcrat.getGrade() > this->signGrade)
	{
		throw AForm::GradeTooHighException();
		return;
	}

	this->setIsSigned(true);
}

/******************************************************************************\
 * VALIDATORS
\******************************************************************************/

void AForm::validateGrade(int grade)
{
	if (grade < 1)
	{
		throw AForm::GradeTooHighException();
		return;
	}

	if (grade > 150)
	{
		throw AForm::GradeTooLowException();
		return;
	}
}

void AForm::validateExecution(Bureaucrat const &executor) const
{
	if (this->isSigned == false)
	{
		throw AForm::UnsignedFormException();
		return;
	}

	if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooHighException();
		return;
	}
}

/******************************************************************************\
 * ERRORS
\******************************************************************************/

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Form grade is too low!";
}

const char *AForm::UnsignedFormException::what(void) const throw()
{
	return "Can't execute an unsigned form!";
}

/******************************************************************************\
 * OPERATORS
\******************************************************************************/

std::ostream &operator<<(std::ostream &out_strm, const AForm &form)
{
	out_strm
		<< form.getName()
		<< " form for "
		<< form.getTarget()
		<< " with sign grade "
		<< form.getSignGrade()
		<< " and execution grade "
		<< form.getExecGrade()
		<< ", signed: "
		<< form.getIsSigned()
		<< "."
		<< std::endl;

	return out_strm;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void AForm::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Form: " << this << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Target: " << this->target << std::endl;
	std::cout << "Is signed: " << this->isSigned << std::endl;
	std::cout << "Sign grade: " << this->signGrade << std::endl;
	std::cout << "Execute grade: " << this->execGrade << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
