/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 12:49:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int horde_size = 10;
	Zombie *horde;

	horde = zombieHorde(horde_size, "Steve");
	if (horde == NULL)
	{
		std::cout << "Error initializing Zombie Horde." << std::endl;
		return 0;
	}

	int i = 0;
	while (i < horde_size)
	{
		horde[i].announce();
		i++;
	}

	delete[] horde;
	return 0;
}
