/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 14:23:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA
{

public:
	HumanA(std::string name, Weapon &weapon);

	void attack(void);

private:
	std::string _name;
	Weapon &_weapon;
};

#endif
