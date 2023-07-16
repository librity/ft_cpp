/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:10:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/16 23:48:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Sed
{

public:
	static void main(int argc, char *argv[]);

	Sed(std::string filename, std::string s1, std::string s2);

private:
	std::string input_file_path;
	std::ifstream input_file;

	std::string output_file_path;
	std::ofstream output_file;

	std::string s1;
	std::string s2;

	void open_input_file_or_die(void);
	void open_output_file_or_die(void);
	void replace(void);
	void replace_line(std::string &line);
	void close_files(void);
};

#endif
