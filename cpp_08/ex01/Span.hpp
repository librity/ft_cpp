/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:56:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 14:03:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstddef>
#include <cmath>

#include <vector>
#include <algorithm>

class Span
{
public:
	Span(void);
	Span(Span const &copy_me);
	Span &operator=(Span const &copy_me);
	~Span(void);

	Span(unsigned int N);

	void addNumber(int n);
	int shortestSpan(void);
	int longestSpan(void);

	class FullException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	void fill(void);
	void inspect(void) const;

	template <typename T>
	void copy_range(T range_start, T range_end);
	class CopyRangeException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

private:
	std::vector<int> container;
	size_t max_size;

	size_t space_left(void) const;

	void set_size(size_t new_size);

	void sort(void);
};

#include "Span.tpp"

#endif
