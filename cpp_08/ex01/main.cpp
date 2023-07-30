/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 14:14:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Span.hpp"

#define RAND_MODULUS 1000000000000
void test_range(size_t max_size)
{
	Span span(max_size);

	try
	{
		std::vector<int> bad_range(max_size + 1);
		span.copy_range(bad_range.begin(), bad_range.end());
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::vector<int> rand_range(max_size);
	size_t i = 0;
	while (i < max_size)
	{
		rand_range[i] = std::rand() % RAND_MODULUS;
		++i;
	}
	span.copy_range(rand_range.begin(), rand_range.end());

	span.inspect();

	try
	{
		span.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "span.shortestSpan() = " << span.shortestSpan() << std::endl;
	std::cout << "span.longestSpan() = " << span.longestSpan() << std::endl;
}

int main(void)
{
	std::srand(std::time(NULL));

	// test_range(5);
	test_range(10000);
	// test_range(1000000);

	return 0;
}

// int main(void)
// {
// 	Span sp = Span(5);

// 	try
// 	{
// 		sp.shortestSpan();
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 	}
// 	try
// 	{
// 		sp.longestSpan();
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 	}

// 	sp.addNumber(6);

// 	try
// 	{
// 		sp.shortestSpan();
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 	}
// 	try
// 	{
// 		sp.longestSpan();
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 	}

// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	sp.inspect();

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	try
// 	{
// 		sp.addNumber(11);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 	}

// 	return 0;
// }
