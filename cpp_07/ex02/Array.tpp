/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:08:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/23 13:28:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

template <typename T>
Array<T>::Array(void)
	: arr(NULL), arr_size(0)
{
}

template <typename T>
Array<T>::Array(Array<T> const &copy_me)
	: arr(NULL), arr_size(0)
{
	*this = copy_me;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &copy_me)
{
	if (this == &copy_me)
		return *this;

	this->set_size(copy_me.arr_size);
	if (arr_size == 0)
	{
		arr = NULL;
		return *this;
	}

	if (arr != NULL)
		delete[] arr;
	arr = new T[arr_size];

	size_t i = 0;
	while (i < arr_size)
	{
		arr[i] = copy_me[i];
		i++;
	}

	return *this;
}

template <typename T>
Array<T>::~Array<T>(void)
{
	if (arr != NULL)
		delete[] arr;
}

/******************************************************************************\
 * CONSTRUCTORS
\******************************************************************************/

template <typename T>
Array<T>::Array(unsigned int n)
	: arr(NULL), arr_size(n)
{
	if (arr_size == 0)
		return;

	arr = new T[arr_size];
}

template <typename T>
void Array<T>::bzero_array(void)
{
	size_t i = 0;
	while (i < arr_size)
	{
		arr[i] = 0;
		i++;
	}
}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

template <typename T>
size_t Array<T>::size(void) const
{
	return arr_size;
}

/******************************************************************************\
 * SETTERS
\******************************************************************************/

template <typename T>
void Array<T>::set_size(size_t new_size)
{
	const_cast<size_t &>(this->arr_size) = new_size;
}

/******************************************************************************\
 * OPERATORS
\******************************************************************************/

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= arr_size)
		throw Array<T>::OutOfBoundsException();

	return arr[index];
}

template <typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= arr_size)
		throw Array<T>::OutOfBoundsException();

	return arr[index];
}

/******************************************************************************\
 * EXCEPTIONS
\******************************************************************************/

template <typename T>
const char *Array<T>::OutOfBoundsException::what(void) const throw()
{
	return "index out of bounds!";
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

template <typename T>
void Array<T>::inspect(void) const
{
	std::cout << "===============================================" << std::endl;

	std::cout << "Array: " << this << std::endl;
	std::cout << "arr_size: " << arr_size << std::endl;

	std::cout << "arr: ";
	size_t i = 0;
	while (i < arr_size)
	{
		std::cout << arr[i] << " ";
		i++;
	}
	std::cout << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
