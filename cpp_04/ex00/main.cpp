/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 18:25:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	i->inspect();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	j->inspect();

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	meta->inspect();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->inspect();
	wrong_i->makeSound();

	std::cout << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_meta->inspect();

	delete wrong_meta;
	delete wrong_i;

	Dog a;
	a.inspect();
	Dog b(a);
	b.inspect();
	Dog c;
	c.inspect();
	c = b;
	c.inspect();

	return 0;
}
