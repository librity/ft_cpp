/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 15:19:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{

public:
	Animal(void);
	Animal(const Animal &animal);
	virtual ~Animal(void);
	virtual Animal &operator=(const Animal &animal);

	std::string getType(void) const;

	virtual void makeSound(void) const = 0;

	virtual void inspect(void) const = 0;

protected:
	std::string type;
};

#endif
