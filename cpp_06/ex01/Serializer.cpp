/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 17:55:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/******************************************************************************\
 * STATIC
\******************************************************************************/

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

void Serializer::fill_data(Data *ptr)
{
	int i = 0;
	while (i < DATA_SIZE)
	{
		ptr->bytes[i] = i;
		i++;
	}
}

void Serializer::print_data(Data *ptr)
{
	std::cout << "*ptr = " << ptr << std::endl;
	std::cout << "Data: ";

	int i = 0;
	while (i < DATA_SIZE)
	{
		print_bits(ptr->bytes[i]);
		i++;
	}

	std::cout << std::endl;
}

void Serializer::print_bits(uint8_t number)
{
	int i;

	std::cout << "|";
	i = (sizeof(uint8_t) * 8) - 1;
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
	std::cout << " ";
}

/******************************************************************************\
 * OCCF
\******************************************************************************/

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &serializer)
{
	*this = serializer;
}

Serializer &Serializer::operator=(const Serializer &serializer)
{
	(void)serializer;

	return *this;
}

Serializer::~Serializer() {}
