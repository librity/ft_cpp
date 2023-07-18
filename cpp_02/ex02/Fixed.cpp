/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 10:22:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************\
 * CONSTRUCTORS/DESTRUCTORS
\******************************************************************************/

Fixed::Fixed(void) : value(0)
{
}

Fixed::Fixed(const int int_value)
	: value(int_value << this->frac_bits)
{
}

Fixed::Fixed(const float fp_value)
{

	int exponent = 1 << this->frac_bits;
	float scaled = fp_value * exponent;
	int rounded = (int)roundf(scaled);
	this->value = rounded;
}

Fixed::Fixed(const Fixed &fixed)
{

	*this = fixed;
}

Fixed::~Fixed(void)
{
}

/******************************************************************************\
 * GETTERS/SETTERS
\******************************************************************************/

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

/******************************************************************************\
 * TRANSFORMERS
\******************************************************************************/

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

/******************************************************************************\
 * OPERATORS
\******************************************************************************/

Fixed &Fixed::operator=(const Fixed &fixed)
{

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

/******************************************************************************\
 * COMPARISON OPERATORS
\******************************************************************************/

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->value != fixed.getRawBits();
}

/******************************************************************************\
 * ARITHMETIC OPERATORS
\******************************************************************************/

Fixed Fixed::operator+(const Fixed &fixed) const
{
	float fp_sum = this->toFloat() + fixed.toFloat();

	return Fixed(fp_sum);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	float fp_sum = this->toFloat() - fixed.toFloat();

	return Fixed(fp_sum);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	float fp_product = this->toFloat() * fixed.toFloat();

	return Fixed(fp_product);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	float fp_product = this->toFloat() / fixed.toFloat();

	return Fixed(fp_product);
}

/******************************************************************************\
 * INCREMENT/DECREMENT OPERATORS
\******************************************************************************/

Fixed Fixed::operator++(void)
{
	this->value += 1;

	Fixed result = *this;
	return (result);
}

Fixed Fixed::operator++(int)
{
	Fixed result = *this;

	this->value += 1;
	return (result);
}

Fixed Fixed::operator--(void)
{
	this->value -= 1;

	Fixed result = *this;
	return (result);
}

Fixed Fixed::operator--(int)
{
	Fixed result = *this;

	this->value -= 1;
	return (result);
}

/******************************************************************************\
 * MIN/MAX
\******************************************************************************/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;

	return b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;

	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;

	return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;

	return b;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

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
