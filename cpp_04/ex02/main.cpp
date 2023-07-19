/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 15:21:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// Animal unicorn;
	// Won't compile: can't instantiate an abstract class!

	const Animal *dog = new Dog();
	// |> DEBUG: Animal of type EMPTY TYPE created: 0x4de8c80
	// |> DEBUG: Brain created: 0x4de92a0
	// |> DEBUG: Dog of type Dog created: 0x4de8c80
	const Animal *cat = new Cat();
	// |> DEBUG: Animal of type EMPTY TYPE created: 0x4dea0a0
	// |> DEBUG: Brain created: 0x4dea280
	// |> DEBUG: Cat of type Cat created: 0x4dea0a0
	delete dog;
	// |> DEBUG: Brain 0x4de92a0 destroyed
	// |> DEBUG: Dog 0x4de8c80 destroyed
	// |> DEBUG: Animal 0x4de8c80 destroyed
	delete cat;
	// |> DEBUG: Brain 0x4dea280 destroyed
	// |> DEBUG: Cat 0x4dea0a0 destroyed
	// |> DEBUG: Animal 0x4dea0a0 destroyed

	int i;
	int total = 8;
	const Animal *animals[total];
	i = 0;
	while (i < total)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
	// |> DEBUG: Animal of type EMPTY TYPE created: 0x4de8c80                                                                                                                                    [16/9355]
	// |> DEBUG: Brain created: 0x4de92a0
	// |> DEBUG: Cat of type Cat created: 0x4de8c80
	// |> DEBUG: Animal of type EMPTY TYPE created: 0x4dea0a0
	// |> DEBUG: Brain created: 0x4dea280
	// |> DEBUG: Dog of type Dog created: 0x4dea0a0
	// |> DEBUG: Animal of type EMPTY TYPE created: 0x4deb080
	// |> ...
	i = 0;
	while (i < total)
	{
		animals[i]->makeSound();
		i++;
	}
	// |> Meow!
	// |> Wooof!
	// |> Meow!
	// |> ...
	i = 0;
	while (i < total)
	{
		delete animals[i];
		i++;
	}
	// |> DEBUG: Brain 0x4de92a0 destroyed
	// |> DEBUG: Cat 0x4de8c80 destroyed
	// |> DEBUG: Animal 0x4de8c80 destroyed
	// |> DEBUG: Brain 0x4dea280 destroyed
	// |> ...

	return 0;
}
