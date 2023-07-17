/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/17 16:00:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	// |> Default constructor called
	Fixed b(a);
	// |> Copy constructor called
	// |> Copy assignment operator called
	// |> getRawBits member function called
	Fixed c;
	// |> Default constructor called
	c = b;
	// |> Copy assignment operator called
	// |> getRawBits member function called

	std::cout << a.getRawBits() << std::endl;
	// |> getRawBits member function called
	// |> 0
	std::cout << b.getRawBits() << std::endl;
	// |> getRawBits member function called
	// |> 0
	std::cout << c.getRawBits() << std::endl;
	// |> getRawBits member function called
	// |> 0

	return 0;
	// |> Destructor called
	// |> Destructor called
	// |> Destructor called
}
