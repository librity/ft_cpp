/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 22:25:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DEBUG: ScavTrap " + this->name + " created: " << this << std::endl;

	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav_trap) : ClapTrap(scav_trap)
{
	std::cout << "DEBUG: ScavTrap copy constructor called" << std::endl;

	*this = scav_trap;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "DEBUG: ScavTrap " << this << " destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav_trap)
{
	std::cout << "DEBUG: ScavTrap copy assignment operator called" << std::endl;

	if (this == &scav_trap)
		return *this;

	this->name = scav_trap.get_name();
	this->hit_points = scav_trap.get_hit_points();
	this->energy_points = scav_trap.get_energy_points();
	this->attack_damage = scav_trap.get_attack_damage();

	return *this;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void ScavTrap::attack(const std::string &target)
{
	if (this->is_dead())
	{
		std::cout << this->name + " has died and can't attack." << std::endl;
		return;
	}

	if (this->is_tired())
	{
		std::cout << this->name + " ran out of energy and can't attack." << std::endl;
		return;
	}

	this->energy_points -= 1;
	std::cout
		<< "ScavTrap "
		<< this->name + " attacks " + target + ", causing "
		<< this->attack_damage
		<< " points of damage!"
		<< std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->is_dead())
	{
		std::cout << this->name + " has died and can't guard the gate." << std::endl;
		return;
	}

	std::cout << this->name + " is now in Gate keeper mode!" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void ScavTrap::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "ScavTrap: " << this << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Hit points: " << this->hit_points << std::endl;
	std::cout << "Energy points: " << this->energy_points << std::endl;
	std::cout << "Attack damage: " << this->attack_damage << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
