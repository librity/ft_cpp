/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 13:16:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("A");
	a.inspect();
	ScavTrap b(a);
	b.inspect();
	ScavTrap c("C");
	c.inspect();
	c = b;
	c.inspect();

	ScavTrap grumpy("Grumpy");
	grumpy.inspect();
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.attack("Roland");
	grumpy.takeDamage(2);
	grumpy.beRepaired(2);
	grumpy.guardGate();
	grumpy.inspect();

	ScavTrap dopey("Dopey");
	dopey.inspect();
	dopey.takeDamage(2);
	dopey.takeDamage(2);
	dopey.takeDamage(2);
	dopey.takeDamage(2);
	dopey.takeDamage(2);
	dopey.takeDamage(2);
	dopey.takeDamage(2);
	dopey.attack("Roland");
	dopey.beRepaired(2);
	grumpy.guardGate();
	dopey.inspect();

	ScavTrap doc("Doc");
	doc.inspect();
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.beRepaired(2);
	doc.attack("Roland");
	doc.takeDamage(2);
	grumpy.guardGate();
	doc.inspect();

	return 0;
}
