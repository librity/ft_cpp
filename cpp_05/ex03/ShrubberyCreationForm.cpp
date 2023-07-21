/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 19:04:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("shrubbery creation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("shrubbery creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
	: AForm(form)
{
	*this = form;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form)
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

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->validateExecution(executor);

	std::ofstream output_file;
	std::string output_file_name = this->target + "_shrubbery";

	output_file.open(output_file_name.c_str(), std::ios::out);
	if (output_file.fail())
	{
		throw ShrubberyCreationForm::OpenFileException();
		return;
	}

	output_file << TREES;
	output_file.close();
}

/******************************************************************************\
 * ERRORS
\******************************************************************************/

const char *ShrubberyCreationForm::OpenFileException::what(void) const throw()
{
	return "Couldn't open output file!";
}
