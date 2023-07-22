/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 17:18:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>

enum ScalarType
{
	UNKNOWN,

	CHAR,
	INT,
	FLOAT,
	DOUBLE,

	NAN,
	POS_INF,
	NEG_INF,
};

struct ResolveEntry
{
	ScalarType key;
	bool (*value)(void);
};

struct CastEntry
{
	ScalarType key;
	void (*value)(void);
};

struct PrintEntry
{
	ScalarType key;
	void (*value)(void);
};

class ScalarConverter
{

public:
	static void convert(const std::string &convert_me);

private:
	static std::string string;
	static ScalarType type;
	static char char_cast;
	static int int_cast;
	static float float_cast;
	static double double_cast;

	// RESOLVE
	static void resolve_type(void);

	static bool is_nan(void);
	static bool is_pos_inf(void);
	static bool is_neg_inf(void);

	static bool is_char(void);
	static bool is_int(void);
	static bool is_float(void);
	static bool is_double(void);

	// CAST
	static void cast_values(void);

	static void cast_char(void);
	static void cast_int(void);
	static void cast_float(void);
	static void cast_double(void);

	// PRINT
	static void print_results(void);

	static void print_nan(void);
	static void print_pos_inf(void);
	static void print_neg_inf(void);
	static void print_scalar(void);
	static void print_impossible(void);

	// UTILS
	static bool char_in(char needle, std::string haystack);

	// OCCF
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &conv);
	ScalarConverter &operator=(const ScalarConverter &conv);
	~ScalarConverter(void);
};

#endif
