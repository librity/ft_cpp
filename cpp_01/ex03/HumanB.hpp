/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 14:26:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB
{

public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);

	void attack(void);

private:
	std::string _name;
	Weapon *_weapon;
};

#endif
