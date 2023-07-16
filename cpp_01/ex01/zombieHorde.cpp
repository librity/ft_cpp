/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:58 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 12:49:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;

	Zombie *horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}

	return horde;
}
