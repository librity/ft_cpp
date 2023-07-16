/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 13:04:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The memory address of the string variable:	" << &string << std::endl;
	std::cout << "The memory address held by stringPTR:		" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:		" << &stringREF << std::endl;

	std::cout << "The value of the string variable:	" << string << std::endl;
	std::cout << "The value pointed to by stringPTR:	" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:	" << stringREF << std::endl;

	return 0;
}
