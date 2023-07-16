/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 12:41:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Creating Zombie: " << this << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying Zombie: " + this->_name << std::endl;
}

void Zombie::set_name(std::string name)
{
	std::cout << "Setting Zombie " << this << "'s name: " + name << std::endl;
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
