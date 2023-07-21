/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/21 17:49:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

typedef class Bureaucrat Bureaucrat;

class AForm
{

public:
	AForm(void);
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &from);
	virtual AForm &operator=(const AForm &from);
	virtual ~AForm(void);

	const std::string &getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	const std::string &getTarget(void) const;

	void beSigned(const Bureaucrat &bcrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class UnsignedFormException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	void inspect(void) const;

protected:
	std::string target;

	void setName(std::string name);
	void setIsSigned(bool isSigned);
	void setSignGrade(int newGrade);
	void setExecGrade(int newGrade);

	void validateExecution(Bureaucrat const &executor) const;

private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;

	static void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &out_strm, const AForm &form);

#endif
