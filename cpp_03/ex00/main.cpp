/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 11:37:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	a.inspect();
	ClapTrap b(a);
	b.inspect();
	ClapTrap c("C");
	c.inspect();
	c = b;
	c.inspect();

	ClapTrap grumpy("Grumpy");
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
	grumpy.inspect();

	ClapTrap dopey("Dopey");
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
	dopey.inspect();

	ClapTrap doc("Doc");
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
	doc.inspect();

	return 0;
}
