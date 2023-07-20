/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/20 02:52:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

typedef class Bureaucrat Bureaucrat;

class Form
{

public:
	Form(void);
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &from);
	Form &operator=(const Form &from);
	~Form(void);

	const std::string &getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	void beSigned(const Bureaucrat &bcrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	void inspect(void) const;

private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;

	void setName(std::string name);
	void setIsSigned(bool isSigned);
	void setSignGrade(int newGrade);
	void setExecGrade(int newGrade);

	static void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &out_strm, const Form &form);

#endif
