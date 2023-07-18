/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 12:20:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "DEBUG: ClapTrap " + this->name + " created: " << this << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap)
{
	std::cout << "DEBUG: ClapTrap copy constructor called" << std::endl;

	*this = clap_trap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "DEBUG: ClapTrap " << this << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap_trap)
{
	std::cout << "DEBUG: ClapTrap copy assignment operator called" << std::endl;

	if (this == &clap_trap)
		return *this;

	this->name = clap_trap.get_name();
	this->hit_points = clap_trap.get_hit_points();
	this->energy_points = clap_trap.get_energy_points();
	this->attack_damage = clap_trap.get_attack_damage();

	return *this;
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

const std::string &ClapTrap::get_name(void) const
{
	const std::string &name = this->name;

	return name;
}

int ClapTrap::get_hit_points(void) const
{
	return this->hit_points;
}

int ClapTrap::get_energy_points(void) const
{
	return this->energy_points;
}

int ClapTrap::get_attack_damage(void) const
{
	return this->attack_damage;
}

/******************************************************************************\
 * PROPERTIES
\******************************************************************************/

bool ClapTrap::is_dead(void) const
{
	return this->hit_points <= 0;
}

bool ClapTrap::is_tired(void) const
{
	return this->energy_points <= 0;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void ClapTrap::attack(const std::string &target)
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
		<< this->name + " attacks " + target + ", causing "
		<< this->attack_damage
		<< " points of damage!"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->is_dead())
	{
		std::cout << this->name + " has died and can't take any more damage." << std::endl;
		return;
	}

	this->hit_points -= amount;
	std::cout
		<< this->name + " takes " << amount << " points of damage!"
		<< std::endl;

	if (this->is_dead())
	{
		this->hit_points = 0;
		std::cout << this->name + " has died!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->is_dead())
	{
		std::cout << this->name + " has died and can't be repaired." << std::endl;
		return;
	}

	if (this->is_tired())
	{
		std::cout << this->name + " ran out of energy and can't be repaired." << std::endl;
		return;
	}

	this->energy_points -= 1;
	this->hit_points += amount;
	std::cout
		<< this->name + " recovers " << amount << " points of damage!"
		<< std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void ClapTrap::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "ClapTrap: " << this << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Hit points: " << this->hit_points << std::endl;
	std::cout << "Energy points: " << this->energy_points << std::endl;
	std::cout << "Attack damage: " << this->attack_damage << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
