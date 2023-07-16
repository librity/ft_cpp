/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 23:52:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void Sed::main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Argument error!" << std::endl;
		std::cout << "\tRun Sed::main with an input filename, a string to replace and and a string to replace with." << std::endl;

		std::exit(1);
	}

	Sed sed(argv[1], argv[2], argv[3]);

	sed.open_input_file_or_die();
	sed.open_output_file_or_die();
	sed.replace();
	sed.close_files();

	std::exit(0);
}

Sed::Sed(std::string input_file_path, std::string s1, std::string s2)
	: input_file_path(input_file_path), s1(s1), s2(s2)
{
	this->output_file_path = input_file_path + ".replace";
}

void Sed::open_input_file_or_die(void)
{
	this->input_file.open(this->input_file_path.c_str(), std::ios::in);

	if (this->input_file.fail())
	{
		std::cout << "IO error!" << std::endl;
		std::cout << "\tCouldn't open input file: " << this->input_file_path << std::endl;

		std::exit(1);
	}
}

void Sed::open_output_file_or_die(void)
{
	this->output_file.open(this->output_file_path.c_str(), std::ios::out);

	if (this->output_file.fail())
	{
		std::cout << "IO error!" << std::endl;
		std::cout << "\tCouldn't open output file: " << this->output_file_path << std::endl;

		std::exit(1);
	}
}

void Sed::replace(void)
{
	std::string line;

	while (std::getline(this->input_file, line))
	{
		this->replace_line(line);
		this->output_file << line << std::endl;
	}
}

void Sed::replace_line(std::string &line)
{
	size_t next = 0;

	while ((next = line.find(this->s1, next)) != std::string::npos)
	{
		line.erase(next, this->s1.length());
		line.insert(next, this->s2);
		next += this->s2.length();
	}
}

void Sed::close_files(void)
{
	this->output_file.close();
	this->input_file.close();
}
