/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/17 11:20:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{

public:
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
};

struct CallbackEntry
{
	const char *key;
	void (Harl::*value)(void);
};

#endif
