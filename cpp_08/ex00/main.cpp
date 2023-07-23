/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/23 16:46:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include <vector>
#include <set>
#include <deque>

#include "easyfind.hpp"

template <typename ScalarT>
void test_vector(void)
{
	std::vector<ScalarT> test_type_set;
	test_type_set.push_back(42);
	test_type_set.push_back(43);
	test_type_set.push_back(44);
	try
	{
		std::cout << *easyfind(test_type_set, 42) << std::endl;
		std::cout << *easyfind(test_type_set, 43) << std::endl;
		std::cout << *easyfind(test_type_set, 44) << std::endl;
		std::cout << *easyfind(test_type_set, 45) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

template <typename ScalarT>
void test_set(void)
{
	std::set<ScalarT> test_type_set;
	test_type_set.insert(42);
	test_type_set.insert(43);
	test_type_set.insert(44);
	try
	{
		std::cout << *easyfind(test_type_set, 42) << std::endl;
		std::cout << *easyfind(test_type_set, 43) << std::endl;
		std::cout << *easyfind(test_type_set, 44) << std::endl;
		std::cout << *easyfind(test_type_set, 45) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

template <typename ScalarT>
void test_deque(void)
{
	std::deque<ScalarT> test_type_set;
	test_type_set.push_back(42);
	test_type_set.push_back(43);
	test_type_set.push_back(44);
	try
	{
		std::cout << *easyfind(test_type_set, 42) << std::endl;
		std::cout << *easyfind(test_type_set, 43) << std::endl;
		std::cout << *easyfind(test_type_set, 44) << std::endl;
		std::cout << *easyfind(test_type_set, 45) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "========= VECTORS =========" << std::endl;
	test_vector<short>();
	test_vector<char>();
	test_vector<int>();
	test_vector<float>();
	test_vector<double>();

	std::cout << "========= SETS =========" << std::endl;
	test_set<short>();
	test_set<char>();
	test_set<int>();
	test_set<float>();
	test_set<double>();

	std::cout << "========= DEQUES =========" << std::endl;
	test_deque<short>();
	test_deque<char>();
	test_deque<int>();
	test_deque<float>();
	test_deque<double>();

	return 0;
}
