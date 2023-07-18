/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 17:12:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clap_trap);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &clap_trap);

	std::string get_name(void) const;
	int get_hit_points(void) const;
	int get_energy_points(void) const;
	int get_attack_damage(void) const;

	bool is_dead(void) const;
	bool is_tired(void) const;

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void inspect(void) const;

protected:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;
};

#endif
