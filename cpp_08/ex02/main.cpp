/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:07:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 15:34:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mut_stack;
	mut_stack.push(5);
	mut_stack.push(17);
	std::cout << mut_stack.top() << std::endl;
	mut_stack.pop();
	std::cout << mut_stack.size() << std::endl;
	mut_stack.push(3);
	mut_stack.push(5);
	mut_stack.push(737);

	mut_stack.push(0);
	MutantStack<int>::iterator it = mut_stack.begin();
	MutantStack<int>::iterator ite = mut_stack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	mut_stack.inspect();

	std::stack<int> normal_stack(mut_stack);
	std::cout << "normal_stack copy: ";
	while (!normal_stack.empty())
	{
		std::cout << ' ' << normal_stack.top();
		normal_stack.pop();
	}
	std::cout << std::endl;

	return 0;
}
