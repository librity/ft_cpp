/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 14:52:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name + " can't attack without a weapon!" << std::endl;
		return;
	}

	std::cout << this->_name + " attacks with their " + this->_weapon->getType() << std::endl;
}
