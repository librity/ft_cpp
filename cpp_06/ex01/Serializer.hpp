/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 18:50:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#define DATA_SIZE 10

struct Data
{
	uint8_t bytes[DATA_SIZE];
};

class Serializer
{

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

	static void fill_data(Data *ptr);
	static void print_data(Data *ptr);
	static void print_bits(uint8_t number);

private:
	// OCCF
	Serializer(void);
	Serializer(const Serializer &conv);
	Serializer &operator=(const Serializer &conv);
	~Serializer(void);
};

#endif
