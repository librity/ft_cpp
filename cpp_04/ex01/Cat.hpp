/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 01:17:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	Cat(const Cat &cat);
	virtual ~Cat(void);
	virtual Cat &operator=(const Cat &cat);

	Brain *get_brain(void) const;
	void set_idea(std::string idea, int index);

	virtual void makeSound(void) const;

	virtual void inspect(void) const;

private:
	Brain *brain;
};

#endif
