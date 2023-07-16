/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 11:44:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Creating Zombie: " + this->_name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying Zombie: " + this->_name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
