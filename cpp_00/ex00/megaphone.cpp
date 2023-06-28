/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:50:22 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/06/28 22:54:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string to_upper(std::string str)
{
	int i;
	int length;

	length = str.length();
	i = 0;
	while (i < length)
	{
		str[i] = std::toupper(str[i]);
		i++;
	}

	return str;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string token;
	argv++;
	while (*argv != NULL)
	{
		token = to_upper(*argv);

		std::cout << token;
		argv++;
	}
	std::cout << std::endl;

	return (0);
}
