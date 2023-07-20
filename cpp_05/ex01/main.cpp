/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/20 02:52:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form drv_license("Driver's License", 0, 100);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	try
	{
		Form drv_license("Driver's License", 151, 100);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	try
	{
		Form drv_license("Driver's License", 100, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	try
	{
		Form drv_license("Driver's License", 100, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	try
	{
		Form drv_license("Driver's License", 100, 100);
		std::cout << drv_license;

		Bureaucrat steve("Steve", 101);
		steve.signForm(drv_license);
		std::cout << drv_license;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	try
	{
		Form drv_license("Driver's License", 100, 100);
		std::cout << drv_license;

		Bureaucrat steve("Steve", 100);
		steve.signForm(drv_license);
		std::cout << drv_license;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}

	return 0;
}
