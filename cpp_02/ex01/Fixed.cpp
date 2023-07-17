/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 01:18:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
	: value(int_value << this->frac_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fp_value)
{
	std::cout << "Float constructor called" << std::endl;

	int exponent = 1 << this->frac_bits;
	float scaled = fp_value * exponent;
	int rounded = (int)roundf(scaled);
	this->value = rounded;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	int exponent = 1 << this->frac_bits;

	return (int)this->value / exponent;
}

float Fixed::toFloat(void) const
{
	float exponent = 1 << this->frac_bits;

	return (float)this->value / exponent;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &fixed)
	{
		this->value = fixed.getRawBits();
	}

	return *this;
}

std::ostream &operator<<(std::ostream &out_strm, const Fixed &fixed)
{
	out_strm << fixed.toFloat();

	return out_strm;
}

void Fixed::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "Fixed point number: " << this << std::endl;
	std::cout << "Fractional bits: " << this->frac_bits << std::endl;
	std::cout << "Raw bits:\t";
	Fixed::print_bits(this->getRawBits());
	std::cout << "Int bits:\t";
	Fixed::print_bits(this->toInt());
	std::cout << "Float bits:\t";
	Fixed::print_bits(this->toFloat());
	std::cout << "=====================================================" << std::endl;
	std::cout << std::endl;
}

void Fixed::print_bits(int number)
{
	int i;

	std::cout << "|";
	i = (sizeof(int) * 8) - 1;
	while (i >= 0)
	{
		if (number & (1u << i))
			std::cout << "1";
		else
			std::cout << "0";

		if (i % 8 == 0)
			std::cout << "|";
		i--;
	}
	std::cout << std::endl;
}

void Fixed::print_bits(float number)
{
	int i;
	int *float_cast = (int *)&number;

	std::cout << "|";
	i = (sizeof(float) * 8) - 1;
	while (i >= 0)
	{
		if (*float_cast & (1u << i))
			std::cout << "1";
		else
			std::cout << "0";

		if (i % 8 == 0)
			std::cout << "|";
		i--;
	}
	std::cout << std::endl;
}
