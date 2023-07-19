/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 19:01:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{

		Bureaucrat bureaucrat("John", 100);
		std::cout << bureaucrat;

		bureaucrat.incrementGrade();
		std::cout << "Grade after increment: " << bureaucrat.getGrade() << std::endl;
		bureaucrat.decrementGrade();
		std::cout << "Grade after decrement: " << bureaucrat.getGrade() << std::endl;

		Bureaucrat copyBureaucrat(bureaucrat);
		std::cout << "Copy Bureaucrat: " << copyBureaucrat << std::endl;

		Bureaucrat assignedBureaucrat;
		assignedBureaucrat = bureaucrat;
		std::cout << "Assigned Bureaucrat: " << assignedBureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat1("BADBAD", 0);
		Bureaucrat bureaucrat2("BADBAD", 0);
		Bureaucrat bureaucrat3("BADBAD", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat1("BADBAD", 151);
		Bureaucrat bureaucrat2("BADBAD", 151);
		Bureaucrat bureaucrat3("BADBAD", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("John", 150);
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("John", 1);
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	Bureaucrat bureaucrat("John", 1);
	try
	{
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	std::cout << bureaucrat;

	return 0;
}
