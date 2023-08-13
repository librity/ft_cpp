/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/08/13 22:21:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdlib>

#include <stack>

class RPN
{

public:
	static void main(int argc, char **argv);

private:
	static std::string input;
	static std::string good_tokens;
	static std::stack<int> stack;

	// ARGS
	static void handle_args_or_die(int argc, char **argv);

	// RPN CALCULATOR
	static void calculate_rpn(void);
	static void handle_token(std::string token);
	static void print_result(void);

	// ERRORS
	static bool bad_token(std::string token);
	static void die(void);

	// OCCF
	RPN(void);
	RPN(const RPN &conv);
	RPN &operator=(const RPN &conv);
	~RPN(void);
};

#endif
