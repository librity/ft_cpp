/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 13:25:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DEBUG: FragTrap " + this->name + " created: " << this << std::endl;

	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &frag_trap) : ClapTrap(frag_trap)
{
	std::cout << "DEBUG: FragTrap copy constructor called" << std::endl;

	*this = frag_trap;
}

FragTrap::~FragTrap(void)
{
	std::cout << "DEBUG: FragTrap " << this << " destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &frag_trap)
{
	std::cout << "DEBUG: FragTrap copy assignment operator called" << std::endl;

	if (this == &frag_trap)
		return *this;

	this->name = frag_trap.get_name();
	this->hit_points = frag_trap.get_hit_points();
	this->energy_points = frag_trap.get_energy_points();
	this->attack_damage = frag_trap.get_attack_damage();

	return *this;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void FragTrap::highFivesGuys(void)
{
	if (this->is_dead())
	{
		std::cout << this->name + " has died and can't high-five the guys." << std::endl;
		return;
	}

	std::cout << this->name + " high-fives everyone around and dances!" << std::endl;
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void FragTrap::inspect(void) const
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;

	std::cout << "FragTrap: " << this << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Hit points: " << this->hit_points << std::endl;
	std::cout << "Energy points: " << this->energy_points << std::endl;
	std::cout << "Attack damage: " << this->attack_damage << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
