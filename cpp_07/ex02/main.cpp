/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/23 13:28:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Array.hpp"

#define ARR_SIZE 5
int main(void)
{
	Array<int> empty_1;
	Array<int> empty_2(0);
	empty_1.inspect();
	empty_2.inspect();

	Array<int> *empty_3 = new Array<int>(0);
	empty_3->inspect();
	delete empty_3;

	Array<int> int_arr(ARR_SIZE);
	int_arr.inspect();
	int_arr[1] = 42;
	int_arr[3] = 42;
	int_arr.inspect();

	Array<double> double_arr(ARR_SIZE);
	double_arr.inspect();
	double_arr[1] = 42.42e-1;
	double_arr[3] = 42.42e-1;
	double_arr.inspect();

	Array<std::string> str_arr(ARR_SIZE);
	str_arr.inspect();
	str_arr[1] = "42.42e-1";
	str_arr[3] = "42.42e-1";
	str_arr.inspect();

	Array<std::string> str_arr2(ARR_SIZE);
	str_arr2 = str_arr;
	str_arr2.inspect();
	str_arr2[1] = "asdasdsadasdasd";
	str_arr2[3] = "asdasdsadasdasd";
	str_arr2.inspect();
	str_arr.inspect();

	Array<std::string> str_arr3(str_arr);
	str_arr3.inspect();
	str_arr3[1] = "asdasdsadasdasd";
	str_arr3[3] = "asdasdsadasdasd";
	str_arr3.inspect();
	str_arr.inspect();

	try
	{
		str_arr3[ARR_SIZE];
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		str_arr3[-1];
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Array<int> arr1(5);
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			arr1[i] = i + 1;
		}

		Array<int> arr2 = arr1;

		std::cout << "arr1: ";
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			std::cout << arr1[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
		{
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;

		arr1[5] = 10;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }
