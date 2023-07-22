/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 19:13:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
}

Base *generate(void)
{
	int resolver = std::rand() % 3;

	if (resolver == 0)
		return new A;

	if (resolver == 1)
		return new B;

	return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "p: A." << std::endl;
		return;
	}

	if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "p: B." << std::endl;
		return;
	}

	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "p: C." << std::endl;
		return;
	}

	std::cout << "p couldn't be identified!" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "p: A." << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "p: B." << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "p: C." << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	std::cout << "p couldn't be identified!" << std::endl;
}
