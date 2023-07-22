/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 17:19:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/******************************************************************************\
 * STATIC
\******************************************************************************/

std::string ScalarConverter::string = "";
ScalarType ScalarConverter::type = UNKNOWN;

char ScalarConverter::char_cast = 0;
int ScalarConverter::int_cast = 0;
float ScalarConverter::float_cast = 0;
double ScalarConverter::double_cast = 0;

void ScalarConverter::convert(const std::string &convert_me)
{
	string = convert_me;

	resolve_type();
	cast_values();
	print_results();
}

/******************************************************************************\
 * RESOLVE
\******************************************************************************/

void ScalarConverter::resolve_type(void)
{
	ResolveEntry callbacks_dict[] = {
		{NAN, &is_nan},
		{POS_INF, &is_pos_inf},
		{NEG_INF, &is_neg_inf},

		{CHAR, &is_char},
		{INT, &is_int},
		{FLOAT, &is_float},
		{DOUBLE, &is_double},

		{UNKNOWN, NULL},
	};

	ResolveEntry *entry = callbacks_dict;
	while (entry->key != UNKNOWN)
	{
		if (entry->value())
		{
			type = entry->key;
			return;
		}

		entry++;
	}
}

bool ScalarConverter::is_nan(void)
{
	if (string == "nan")
		return true;

	if (string == "nanf")
		return true;

	return false;
}

bool ScalarConverter::is_pos_inf(void)
{
	if (string == "+inff")
		return true;

	if (string == "+inf")
		return true;

	return false;
}

bool ScalarConverter::is_neg_inf(void)
{
	if (string == "-inff")
		return true;

	if (string == "-inf")
		return true;

	return false;
}

bool ScalarConverter::is_char(void)
{
	return string.size() == 1;
}

bool ScalarConverter::is_int(void)
{
	if (string.empty())
		return false;
	if (string.size() == 1 && string[0] == '-')
		return false;
	if (string.size() == 1 && string[0] == '+')
		return false;

	size_t i = 0;
	while (i < string.size())
	{
		if (i == 0 && char_in(string[i], "+-"))
		{
			i++;
			continue;
		}

		if (!std::isdigit(string[i]))
			return false;

		i++;
	}

	return true;
}

bool ScalarConverter::is_float(void)
{
	if (string.empty())
		return false;
	if (string[string.size() - 1] != 'f')
		return false;
	if (string.size() == 1 && string[0] == '-')
		return false;
	if (string.size() == 1 && string[0] == '+')
		return false;

	int decimal_count = 0;
	int f_count = 0;
	size_t i = 0;
	while (i < string.size())
	{
		if (i == 0 && char_in(string[i], "+-"))
		{
			i++;
			continue;
		}

		if (!std::isdigit(string[i]) && !char_in(string[i], ".f"))
			return false;

		if (string[i] == '.')
		{
			decimal_count++;
			if (decimal_count > 1)
				return false;
		}

		if (string[i] == 'f')
		{
			f_count++;
			if (f_count > 1)
				return false;
		}

		i++;
	}

	return true;
}

bool ScalarConverter::is_double(void)
{
	if (string.empty())
		return false;
	if (string[string.size() - 1] == 'f')
		return false;
	if (string.size() == 1 && string[0] == '-')
		return false;
	if (string.size() == 1 && string[0] == '+')
		return false;

	int decimal_count = 0;
	int e_count = 0;
	size_t i = 0;
	while (i < string.size())
	{
		if (i == 0 && char_in(string[i], "+-"))
		{
			i++;
			continue;
		}

		if (!std::isdigit(string[i]) && !char_in(string[i], ".eE+-"))
			return false;

		if (string[i] == '.')
		{
			decimal_count++;
			if (decimal_count > 1)
				return false;
		}

		if (char_in(string[i], "eE"))
		{
			e_count++;
			if (e_count > 1 || i == 0 || i == string.size() - 1)
				return false;
		}

		if (char_in(string[i], "+-"))
		{
			if (i > 0 && !char_in(string[i - 1], "eE"))
				return false;
		}

		i++;
	}

	return true;
}

/******************************************************************************\
 * CAST
\******************************************************************************/

void ScalarConverter::cast_values(void)
{
	CastEntry callbacks_dict[] = {
		{CHAR, &cast_char},
		{INT, &cast_int},
		{FLOAT, &cast_float},
		{DOUBLE, &cast_double},
		{UNKNOWN, NULL},
	};

	CastEntry *entry = callbacks_dict;
	while (entry->key != UNKNOWN)
	{
		if (entry->key == type)
		{
			entry->value();
			return;
		}

		entry++;
	}
}

void ScalarConverter::cast_char(void)
{
	char_cast = string[0];

	int_cast = static_cast<int>(char_cast);
	float_cast = static_cast<float>(char_cast);
	double_cast = static_cast<double>(char_cast);
}

void ScalarConverter::cast_int(void)
{
	int_cast = std::atoi(string.c_str());

	char_cast = static_cast<char>(int_cast);
	float_cast = static_cast<float>(int_cast);
	double_cast = static_cast<double>(int_cast);
}

void ScalarConverter::cast_float(void)
{
	float_cast = std::atof(string.c_str());

	char_cast = static_cast<char>(float_cast);
	int_cast = static_cast<int>(float_cast);
	double_cast = static_cast<double>(float_cast);
}

void ScalarConverter::cast_double(void)
{
	double_cast = std::atof(string.c_str());

	char_cast = static_cast<char>(double_cast);
	int_cast = static_cast<int>(double_cast);
	float_cast = static_cast<float>(double_cast);
}

/******************************************************************************\
 * DISPLAY
\******************************************************************************/

void ScalarConverter::print_results(void)
{
	PrintEntry callbacks_dict[] = {
		{NAN, &print_nan},
		{POS_INF, &print_pos_inf},
		{NEG_INF, &print_neg_inf},

		{CHAR, &print_scalar},
		{INT, &print_scalar},
		{FLOAT, &print_scalar},
		{DOUBLE, &print_scalar},

		{UNKNOWN, NULL},
	};

	PrintEntry *entry = callbacks_dict;
	while (entry->key != UNKNOWN)
	{
		if (entry->key == type)
		{
			entry->value();
			return;
		}

		entry++;
	}

	print_impossible();
}

void ScalarConverter::print_nan(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::print_pos_inf(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void ScalarConverter::print_neg_inf(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::print_scalar(void)
{
	std::cout << std::fixed << std::setprecision(1);

	if (std::isprint(char_cast))
		std::cout << "char: '" << char_cast << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << int_cast << std::endl;
	std::cout << "float: " << float_cast << "f" << std::endl;
	std::cout << "double: " << double_cast << std::endl;
}

void ScalarConverter::print_impossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

/******************************************************************************\
 * UTILS
\******************************************************************************/

bool ScalarConverter::char_in(char needle, std::string haystack)
{

	std::string needle_str(1, needle);
	size_t position = haystack.find(needle_str);

	if (position == std::string::npos)
	{
		return false;
	}
	return true;
}

/******************************************************************************\
 * OCCF
\******************************************************************************/

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &conv)
{
	*this = conv;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &conv)
{
	(void)conv;

	return *this;
}

ScalarConverter::~ScalarConverter() {}
