/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 19:15:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	int i;
	int size = 5;
	Base *pointers[size];
	std::srand(std::time(NULL));

	std::cout << "Generating instances..." << std::endl;
	i = 0;
	while (i < size)
	{
		pointers[i] = generate();
		i++;
	}

	std::cout << "Identify by pointer:" << std::endl;
	i = 0;
	while (i < size)
	{
		identify(pointers[i]);
		i++;
	}

	std::cout << "Identify by reference:" << std::endl;
	i = 0;
	while (i < size)
	{
		identify(*pointers[i]);
		i++;
	}

	std::cout << "Free memory..." << std::endl;
	i = 0;
	while (i < size)
	{
		delete pointers[i];
		i++;
	}
}
