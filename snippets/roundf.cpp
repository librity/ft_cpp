/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundf.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:16:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/18 00:16:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c++ -Wall -Wextra -Werror -std=c++98 roundf.cpp && ./a.out

#include <iostream>
#include <cmath>

int main(void)
{
	float number = 123.3123123123123;

	std::cout << number << std::endl;
	std::cout << roundf(number) << std::endl;

	return 0;
}
