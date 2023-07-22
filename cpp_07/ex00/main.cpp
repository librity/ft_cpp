/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 19:55:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"

int main()
{
	int a = 5, b = 10;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

	int x = 15, y = 20;
	std::cout << "Min: " << min(x, y) << std::endl;
	std::cout << "Max: " << max(x, y) << std::endl;

	double p = 3.14, q = 2.71;
	std::cout << "Min: " << min(p, q) << std::endl;
	std::cout << "Max: " << max(p, q) << std::endl;

	return 0;
}

// class Awesome
// {
// public:
// 	Awesome(void) : _n(0) {}
// 	Awesome(int n) : _n(n) {}
// 	Awesome &operator=(Awesome &a)
// 	{
// 		_n = a._n;
// 		return *this;
// 	}
// 	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
// 	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
// 	bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
// 	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
// 	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
// 	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
// 	int get_n() const { return _n; }

// private:
// 	int _n;
// };
// std::ostream &operator<<(std::ostream &o, const Awesome &a)
// {
// 	o << a.get_n();
// 	return o;
// }

// int main(void)
// {
// 	Awesome a(2), b(4);

// 	swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }
