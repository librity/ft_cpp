/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 17:56:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data();
	Serializer::fill_data(data);

	uintptr_t serialized_data;
	Data *deserialized_data;

	Serializer::print_data(data);
	serialized_data = Serializer::serialize(data);
	std::cout << "serialized_data = " << serialized_data << std::endl;
	deserialized_data = Serializer::deserialize(serialized_data);
	Serializer::print_data(deserialized_data);

	delete data;
	return 0;
}
