/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:16:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 00:30:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c++ -Wall -Wextra -Werror -std=c++98 bits.cpp && ./a.out

#include <iostream>
#include <cmath>
#include <bitset>

// My implementation
void print_bits_int(int number)
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

// My implementation
void print_bits_float(float number)
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

// Chat GPT implementation for comparison
void cgpt_print_bits_float(float value)
{
	// Convert the float value to an integer representation
	unsigned int bits = *reinterpret_cast<unsigned int *>(&value);

	// Extract the individual bytes using bitwise operations
	unsigned int byte1 = (bits >> 24) & 0xFF;
	unsigned int byte2 = (bits >> 16) & 0xFF;
	unsigned int byte3 = (bits >> 8) & 0xFF;
	unsigned int byte4 = bits & 0xFF;

	// Print the bits in the desired format
	std::cout
		<< '|'
		<< std::bitset<8>(byte1) << '|'
		<< std::bitset<8>(byte2) << '|'
		<< std::bitset<8>(byte3) << '|'
		<< std::bitset<8>(byte4) << '|'
		<< std::endl;
}

int main(void)
{
	print_bits_int(42);
	print_bits_float(-123.3123123123123e-3);
	cgpt_print_bits_float(-123.3123123123123e-3);

	return 0;
}
