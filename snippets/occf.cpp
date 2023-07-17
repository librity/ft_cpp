/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occf.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:08:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/17 12:22:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c++ -Wall -Wextra -Werror -std=c++98 occf.cpp && ./a.out

#include <iostream>

class MyClass
{
private:
	int *data;
	int size;

public:
	// Default constructor
	MyClass() : data(NULL), size(0)
	{
		std::cout << "Default constructor called." << std::endl;
	}

	// Parameterized constructor
	MyClass(int n) : size(n)
	{
		data = new int[size];
		std::cout << "Parameterized constructor called." << std::endl;
	}

	// Copy constructor
	MyClass(const MyClass &other) : size(other.size)
	{
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
		std::cout << "Copy constructor called." << std::endl;
	}

	// Destructor
	~MyClass()
	{
		delete[] data;
		std::cout << "Destructor called." << std::endl;
	}

	// Copy assignment operator
	MyClass &operator=(const MyClass &other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			data = new int[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}
		std::cout << "Copy assignment operator called." << std::endl;
		return *this;
	}

	// Accessor
	int getSize() const
	{
		return size;
	}
};

int main()
{
	MyClass obj1(5);
	MyClass obj2(obj1); // Copy construction
	MyClass obj3;
	obj3 = obj1; // Copy assignment

	std::cout << "Size of obj1: " << obj1.getSize() << std::endl;
	std::cout << "Size of obj2: " << obj2.getSize() << std::endl;
	std::cout << "Size of obj3: " << obj3.getSize() << std::endl;

	return 0;
}
