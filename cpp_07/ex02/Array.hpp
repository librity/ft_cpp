/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:56:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/23 13:28:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <exception>

template <typename T>
class Array
{
public:
	Array<T>(void);
	Array<T>(Array<T> const &copy_me);
	Array<T> &operator=(Array<T> const &copy_me);
	~Array<T>(void);

	Array<T>(unsigned int n);

	size_t size(void) const;

	T &operator[](size_t index);
	const T &operator[](size_t index) const;
	class OutOfBoundsException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	void inspect(void) const;

private:
	T *arr;
	const size_t arr_size;

	void set_size(size_t new_size);
	void bzero_array(void);
};

#include "Array.tpp"

#endif
