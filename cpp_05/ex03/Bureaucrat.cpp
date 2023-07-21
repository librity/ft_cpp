/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 18:53:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bcrat)
{

	*this = bcrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bcrat)
{
	if (this == &bcrat)
		return *this;

	this->setGrade(bcrat.grade);
	const_cast<std::string &>(this->name) = bcrat.name;

	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

const std::string &Bureaucrat::getName(void) const
{
	return this->name;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

/******************************************************************************\
 * SETTERS
\******************************************************************************/

void Bureaucrat::setGrade(int newGrade)
{
	if (newGrade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return;
	}

	if (newGrade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return;
	}

	this->grade = newGrade;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	this->setGrade(this->grade + 1);
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout
			<< this->name + " signed form " + form.getName()
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< this->name + " couldn't sign form " + form.getName() + " because: " + e.what()
			<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout
			<< this->name + " executed " + form.getName()
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< this->name + " couldn't sign form " + form.getName() + " because: " + e.what()
			<< std::endl;
	}
}

/******************************************************************************\
 * ERRORS
\******************************************************************************/

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat grade is too low!";
}

/******************************************************************************\
 * OPERATORS
\******************************************************************************/

std::ostream &operator<<(std::ostream &out_strm, const Bureaucrat &bcrat)
{
	out_strm
		<< bcrat.getName() + ", bureaucrat grade " << bcrat.getGrade() << "."
		<< std::endl;

	return out_strm;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void Bureaucrat::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "Bureaucrat: " << this << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Grade: " << this->grade << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
