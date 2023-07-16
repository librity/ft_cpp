/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 11:43:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1("Gar");
	zombie1.announce();

	Zombie *zombie2;
	zombie2 = newZombie("Mon");
	zombie2->announce();
	delete zombie2;

	randomChump("Bozia");

	return 0;
}
