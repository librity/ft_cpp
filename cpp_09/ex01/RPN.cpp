/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/08/13 22:26:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string RPN::input = "";
std::string RPN::good_tokens = "0123456789+-/*";
std::stack<int> RPN::stack;

/******************************************************************************\
 * MAIN
\******************************************************************************/

void RPN::main(int argc, char **argv)
{
	handle_args_or_die(argc, argv);

	calculate_rpn();
	print_result();

	std::exit(0);
}

/******************************************************************************\
 * ARGS
\******************************************************************************/

void RPN::handle_args_or_die(int argc, char **argv)
{
	if (argc != 2)
		die();

	input = argv[1];
}

/******************************************************************************\
 * RPN CALCULATOR
\******************************************************************************/

void RPN::calculate_rpn(void)
{
	std::istringstream iss(input);

	std::string token;
	while (iss >> token)
	{
		if (bad_token(token))
			die();

		handle_token(token);
	}

	if (stack.size() != 1)
		die();
}

void RPN::handle_token(std::string token)
{

	if (std::isdigit(token[0]))
	{
		stack.push(std::atoi(token.c_str()));
		return;
	}

	int rhs = stack.top();
	stack.pop();
	int lhs = stack.top();
	stack.pop();

	if (token == "+")
		return stack.push(lhs + rhs);

	if (token == "-")
		return stack.push(lhs - rhs);

	if (token == "/")
		return stack.push(lhs / rhs);

	if (token == "*")
		return stack.push(lhs * rhs);
}

void RPN::print_result(void)
{
	std::cout << stack.top() << std::endl;
}

/******************************************************************************\
 * ERRORS
\******************************************************************************/

bool RPN::bad_token(std::string token)
{
	if (token.length() != 1)
		return false;

	char token_char = token[0];
	std::string::iterator it = good_tokens.begin();
	bool is_good_token = true;
	while (it != good_tokens.end())
	{
		if (token_char == *it)
			is_good_token = false;
		it++;
	}
	return is_good_token;
}

void RPN::die(void)
{
	std::cout << "Error" << std::endl;
	std::exit(1);
}

/******************************************************************************\
 * OCCF
\******************************************************************************/

RPN::RPN(void) {}

RPN::RPN(const RPN &conv)
{
	*this = conv;
}

RPN &RPN::operator=(const RPN &conv)
{
	(void)conv;

	return *this;
}

RPN::~RPN() {}
