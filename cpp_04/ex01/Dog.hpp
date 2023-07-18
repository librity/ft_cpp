/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 01:17:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

public:
	Dog(void);
	Dog(const Dog &dog);
	virtual ~Dog(void);
	virtual Dog &operator=(const Dog &dog);

	Brain *get_brain(void) const;
	void set_idea(std::string idea, int index);

	virtual void makeSound(void) const;

	virtual void inspect(void) const;

private:
	Brain *brain;
};

#endif
