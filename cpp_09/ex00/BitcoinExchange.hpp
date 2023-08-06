/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/08/07 00:22:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

#include <map>

#define ISO_DATE_FORMAT "%Y-%m-%d"

typedef struct tm t_tm;
struct s_time_compare
{
	bool operator()(const t_tm &lhs, const t_tm &rhs) const;
};

class BitcoinExchange
{

public:
	static void main(int argc, char **argv);

	class ParseDateException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

private:
	// ARGS
	static void handle_args_or_die(int argc, char **argv);

	// INPUT
	static std::string input_file_path;
	static std::ifstream input_file;
	static std::string input_header;
	static std::string input_separator;
	static void open_input_file(void);
	static void print_exchange_values(void);
	static void close_input_file(void);

	// EXCHANGE
	static std::map<t_tm, double, s_time_compare> exchange;
	static std::string exchange_file_path;
	static std::ifstream exchange_file;
	static std::string exchange_header;
	static char exchange_separator;
	static void load_exchange(void);
	static double get_rate_for_date(std::string date_str);
	static void dump_exchange(void);
	static double parse_rate(std::string rate_str);
	static t_tm get_min_date(void);
	static t_tm get_max_date(void);

	// DATES
	static bool is_valid_date(std::string date_str);
	static t_tm parse_date(std::string date_str);
	static std::string date_to_str(t_tm date);
	static bool before(t_tm lhs, t_tm rhs);
	static bool after(t_tm lhs, t_tm rhs);
	static t_tm yesterday(t_tm date);

	// BTC VALUE
	static bool is_valid_value(std::string value_str);
	static double parse_value(std::string value_str);

	// OCCF
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &conv);
	BitcoinExchange &operator=(const BitcoinExchange &conv);
	~BitcoinExchange(void);
};

#endif
