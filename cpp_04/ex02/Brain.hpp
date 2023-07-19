/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/19 00:09:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{

public:
	Brain(void);
	Brain(const Brain &brain);
	virtual ~Brain(void);
	virtual Brain &operator=(const Brain &brain);

	std::string get_idea(int index) const;
	void set_idea(std::string idea, int index);

	void inspect(void) const;

private:
	static const int power = 100;
	std::string ideas[Brain::power];
};

#endif
