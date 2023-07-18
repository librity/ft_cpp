/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 10:22:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	// |> 0
	std::cout << ++a << std::endl;
	// |> 0.00390625
	std::cout << a << std::endl;
	// |> 0.00390625
	std::cout << a++ << std::endl;
	// |> 0.00390625
	std::cout << a << std::endl;
	// |> 0.0078125
	std::cout << b << std::endl;
	// |> 10.1016
	std::cout << Fixed::max(a, b) << std::endl;
	// |> 10.1016

	// std::cout << (a > b) << std::endl;
	// std::cout << (a < b) << std::endl;
	// std::cout << (a >= b) << std::endl;
	// std::cout << (a <= b) << std::endl;
	// std::cout << (a == b) << std::endl;
	// std::cout << (a != b) << std::endl;

	// std::cout << a + b << std::endl;
	// std::cout << a - b << std::endl;
	// std::cout << a * b << std::endl;
	// std::cout << a / b << std::endl;

	// std::cout << a++ << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << --a << std::endl;
	// std::cout << a-- << std::endl;

	// std::cout << Fixed::min(a, b) << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}
