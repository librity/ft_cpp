/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 13:36:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	int i;

	FragTrap a("A");
	a.inspect();
	FragTrap b(a);
	b.inspect();
	FragTrap c("C");
	c.inspect();
	c = b;
	c.inspect();

	FragTrap grumpy("Grumpy");
	grumpy.inspect();
	i = 110;
	while (i--)
		grumpy.attack("Roland");
	grumpy.takeDamage(2);
	grumpy.beRepaired(2);
	grumpy.highFivesGuys();
	grumpy.inspect();

	FragTrap dopey("Dopey");
	dopey.inspect();
	dopey.takeDamage(49);
	dopey.takeDamage(49);
	dopey.takeDamage(49);
	dopey.takeDamage(49);
	dopey.attack("Roland");
	dopey.beRepaired(2);
	dopey.highFivesGuys();
	dopey.inspect();

	FragTrap doc("Doc");
	doc.inspect();
	i = 110;
	while (i--)
		doc.beRepaired(2);
	doc.attack("Roland");
	doc.takeDamage(2);
	doc.highFivesGuys();
	doc.inspect();

	return 0;
}
