/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:08:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 14:03:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

Span::Span(void)
	: max_size(0)
{
}
Span::Span(Span const &copy_me)
	: max_size(0)
{
	*this = copy_me;
}

Span &Span::operator=(Span const &copy_me)
{
	if (this == &copy_me)
		return (*this);

	this->set_size(copy_me.max_size);
	container = copy_me.container;
	return (*this);
}

Span::~Span(void) {}

/******************************************************************************\
 * CONSTRUCTORS
\******************************************************************************/

Span::Span(unsigned int N) : max_size(N) {}

/******************************************************************************\
 * GETTERS
\******************************************************************************/

size_t Span::space_left(void) const
{
	return max_size - container.size();
}

/******************************************************************************\
 * SETTERS
\******************************************************************************/

void Span::set_size(size_t new_size)
{
	const_cast<size_t &>(this->max_size) = new_size;
}

/******************************************************************************\
 * ACTIONS
\******************************************************************************/

void Span::addNumber(int n)
{
	if (this->space_left() <= 0)
		throw FullException();

	container.push_back(n);
	sort();
}

int Span::shortestSpan(void)
{
	if (container.size() < 2)
		throw NoSpanException();
	sort();

	int record = container.back();
	int span;
	std::vector<int>::const_iterator it = container.begin() + 1;
	while (it != container.end())
	{
		span = abs(*(it - 1) - *it);
		if (span < record)
			record = span;
		it++;
	}
	return record;
}

int Span::longestSpan(void)
{
	if (container.size() < 2)
		throw NoSpanException();
	sort();

	int smallest = container.front();
	int greatest = container.back();
	return greatest - smallest;
}

/******************************************************************************\
 * UTILS
\******************************************************************************/

void Span::fill(void)
{
	int elements = max_size - container.size();
	while (elements)
	{
		addNumber(pow(2, elements));
		elements--;
	}
}

void Span::sort(void)
{
	std::sort(container.begin(), container.end());
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

const char *Span::FullException::what(void) const throw()
{
	return "span at full capacity!";
}

const char *Span::NoSpanException::what(void) const throw()
{
	return "can't calculate a span with less than two elements!";
}

const char *Span::CopyRangeException::what(void) const throw()
{
	return "range exceeds span capacity!";
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

void Span::inspect(void) const
{
	std::cout << "===============================================" << std::endl;

	std::cout << "Span: " << this << std::endl;
	std::cout << "max_size: " << max_size << std::endl;

	std::cout << "container: ";
	std::vector<int>::const_iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
