/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 22:29:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &frag_trap);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &frag_trap);

	void attack(const std::string &target);
	void highFivesGuys(void);

	void inspect(void) const;
};

#endif
