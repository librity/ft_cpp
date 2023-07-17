/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 01:02:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	// |> Default constructor called

	Fixed const b(10);
	// |> Int constructor called

	Fixed const c(42.42f);
	// |> Float constructor called

	Fixed const d(b);
	// |> Copy constructor called
	// |> Copy assignment operator called
	// |> Float constructor called

	a = Fixed(1234.4321f);
	// |> Copy assignment operator called
	// |> Destructor called

	std::cout << "a is " << a << std::endl;
	// |> a is 1234.43
	std::cout << "b is " << b << std::endl;
	// |> b is 10
	std::cout << "c is " << c << std::endl;
	// |> c is 42.4219
	std::cout << "d is " << d << std::endl;
	// |> d is 10

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// |> a is 1234 as integer
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// |> b is 10 as integer
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// |> c is 42 as integer
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// |> d is 10 as integer

	// Fixed::print_bits(1234.4321f);
	// a.inspect();
	// Fixed::print_bits(10);
	// b.inspect();
	// Fixed::print_bits(42.42f);
	// c.inspect();
	// Fixed::print_bits(10);
	// d.inspect();

	return 0;
	// |> Destructor called
	// |> Destructor called
	// |> Destructor called
	// |> Destructor called
}
