/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 21:21:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T &x)
{
	std::cout << x << "\t";
	return;
}

template <typename T>
void increment(T &x)
{
	x += 10;
	return;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};

	iter(tab, 5, print<int>);
	std::cout << std::endl;

	iter(tab, 5, increment<int>);
	iter(tab, 5, print<int>);
	std::cout << std::endl;

	return 0;
}

// class Awesome
// {
// public:
// 	Awesome(void) : _n(42) { return; }
// 	int get(void) const { return this->_n; }

// private:
// 	int _n;
// };

// std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
// {
// 	o << rhs.get();
// 	return o;
// }

// template <typename T>
// void print(T &x)
// {
// 	std::cout << x << std::endl;
// 	return;
// }

// int main()
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome tab2[5];

// 	iter(tab, 5, print<const int>);
// 	iter(tab2, 5, print<Awesome>);

// 	return 0;
// }
