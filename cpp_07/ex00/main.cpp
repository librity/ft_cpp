/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 19:57:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	// a = 3, b = 2
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	// min(a, b) = 2
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	// max(a, b) = 3

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	// c = chaine2, d = chaine1
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	// min(c, d) = chaine1
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	// max(c, d) = chaine2

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
