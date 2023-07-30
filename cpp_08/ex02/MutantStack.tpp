/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:08:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 15:31:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/******************************************************************************\
 * OCCF
\******************************************************************************/

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &copy_me) : std::stack<T>()
{
	*this = copy_me;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &copy_me)
{
	if (this == &copy_me)
		return *this;

	this->c = copy_me.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack<T>(void) {}

/******************************************************************************\
 * ITERATOR
\******************************************************************************/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

/******************************************************************************\
 * REVERSE ITERATORS
\******************************************************************************/

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

/******************************************************************************\
 * DEBUG
\******************************************************************************/

template <typename T>
void MutantStack<T>::inspect(void) const
{
	std::cout << "===============================================" << std::endl;

	std::cout << "MutantStack: " << this << std::endl;
	std::cout << "size(): " << this->size() << std::endl;

	std::cout << "stack: ";
	const_iterator it = this->begin();
	while (it != this->end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
}
