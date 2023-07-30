/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:56:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 15:30:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>();
	MutantStack<T>(MutantStack<T> const &copy_me);
	MutantStack<T> &operator=(MutantStack<T> const &copy_me);
	~MutantStack<T>();

	typedef typename MutantStack<T>::container_type::iterator iterator;
	iterator begin(void);
	iterator end(void);

	typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
	const_iterator begin(void) const;
	const_iterator end(void) const;

	typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin(void);
	reverse_iterator rend(void);

	typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin(void) const;
	const_reverse_iterator rend(void) const;

	void inspect(void) const;
};

#include "MutantStack.tpp"

#endif
