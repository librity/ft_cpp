/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/20 02:45:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
	std::cout << "DEBUG: Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name)
{
	this->setGrade(grade);

	std::cout << "DEBUG: Bureaucrat " + this->name + " created: " << this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bcrat)
{
	std::cout << "DEBUG: Bureaucrat copy constructor called" << std::endl;

	*this = bcrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bcrat)
{
	std::cout << "DEBUG: Bureaucrat copy assignment operator called" << std::endl;

	if (this == &bcrat)
		return *this;

	this->setGrade(bcrat.grade);
	const_cast<std::string &>(this->name) = bcrat.name;

	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "DEBUG: Bureaucrat " << this << " destroyed" << std::endl;
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

void Bureaucrat::signForm(Form &form) const
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
			<< this->name + " couldn't sign form " + form.getName() + " because " + e.what()
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
