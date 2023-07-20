/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/20 02:44:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Form::Form(void)
	: name(""), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "DEBUG: Form constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(150), execGrade(150)
{
	this->setSignGrade(signGrade);
	this->setExecGrade(execGrade);

	std::cout << "DEBUG: Form " + this->name + " created: " << this << std::endl;
}

Form::Form(const Form &form)
	: name(""), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "DEBUG: Form copy constructor called" << std::endl;

	*this = form;
}

Form &Form::operator=(const Form &form)
{
	std::cout << "DEBUG: Form copy assignment operator called" << std::endl;

	if (this == &form)
		return *this;

	this->setName(form.name);
	this->setIsSigned(form.isSigned);
	this->setSignGrade(form.signGrade);
	this->setExecGrade(form.execGrade);

	return *this;
}

Form::~Form()
{
	std::cout << "DEBUG: Form " << this << " destroyed" << std::endl;
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

const std::string &Form::getName(void) const
{
	return this->name;
}

bool Form::getIsSigned(void) const
{
	return this->isSigned;
}

int Form::getSignGrade(void) const
{

	return this->signGrade;
}

int Form::getExecGrade(void) const
{

	return this->execGrade;
}

/******************************************************************************\
 * SETTERS
\******************************************************************************/

void Form::setName(std::string name)
{
	const_cast<std::string &>(this->name) = name;
}

void Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void Form::setSignGrade(int newGrade)
{
	Form::validateGrade(newGrade);

	const_cast<int &>(this->signGrade) = newGrade;
}

void Form::setExecGrade(int newGrade)
{
	Form::validateGrade(newGrade);

	const_cast<int &>(this->execGrade) = newGrade;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void Form::beSigned(const Bureaucrat &bcrat)
{
	if (bcrat.getGrade() > this->signGrade)
	{
		throw Form::GradeTooLowException();
		return;
	}

	this->setIsSigned(true);
}

/******************************************************************************\
 * VALIDATORS
\******************************************************************************/

void Form::validateGrade(int grade)
{
	if (grade < 1)
	{
		throw Form::GradeTooHighException();
		return;
	}

	if (grade > 150)
	{
		throw Form::GradeTooLowException();
		return;
	}
}

/******************************************************************************\
 * ERRORS
\******************************************************************************/

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Form grade is too low!";
}

/******************************************************************************\
 * OPERATORS
\******************************************************************************/

std::ostream &operator<<(std::ostream &out_strm, const Form &form)
{
	out_strm
		<< form.getName() + " form with sign grade "
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

void Form::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Form: " << this << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Is signed: " << this->isSigned << std::endl;
	std::cout << "Sign grade: " << this->signGrade << std::endl;
	std::cout << "Execute grade: " << this->execGrade << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
