/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 13:24:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

const std::string &Weapon::getType(void)
{
	const std::string &type_ref = this->_type;
	return (type_ref);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
