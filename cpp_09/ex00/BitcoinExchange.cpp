/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/08/13 14:08:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/******************************************************************************\
 * MAIN
\******************************************************************************/

void BitcoinExchange::main(int argc, char **argv)
{
	handle_args_or_die(argc, argv);

	load_exchange();

	open_input_file();
	print_exchange_values();
	close_input_file();

	std::exit(0);
}

/******************************************************************************\
 * ARGS
\******************************************************************************/

void BitcoinExchange::handle_args_or_die(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		std::exit(1);
	}

	input_file_path = argv[1];
}

/******************************************************************************\
 * INPUT
\******************************************************************************/

std::string BitcoinExchange::input_file_path;
std::ifstream BitcoinExchange::input_file;
std::string BitcoinExchange::input_header = "date | value";
std::string BitcoinExchange::input_separator = " | ";

void BitcoinExchange::open_input_file(void)
{
	input_file.open(input_file_path.c_str(), std::ios::in);
	if (input_file.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		std::exit(1);
	}
}

void BitcoinExchange::print_exchange_values(void)
{
	std::string line;
	size_t pos;

	std::string date_str;
	std::string value_str;
	double value;
	double rate;

	while (std::getline(input_file, line))
	{
		if (line == input_header)
			continue;

		pos = line.find(input_separator);
		if (bad_input_line(line, pos))
			continue;

		date_str = line.substr(0, pos);
		if (!is_valid_date(date_str))
			continue;

		value_str = line.substr(pos + 3);
		if (!is_valid_value(value_str))
			continue;

		rate = get_rate_for_date(date_str);
		value = std::atof(value_str.c_str());
		std::cout << date_str + " => " + value_str + " = " << value * rate << std::endl;
	}
}

bool BitcoinExchange::bad_input_line(std::string &line, size_t pos)
{
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return true;
	}

	return false;
}

void BitcoinExchange::close_input_file(void)
{
	input_file.close();
}

/******************************************************************************\
 * EXCHANGE
\******************************************************************************/

std::map<t_tm, double, s_time_compare> BitcoinExchange::exchange;
std::string BitcoinExchange::exchange_file_path = "./data.csv";
std::ifstream BitcoinExchange::exchange_file;
std::string BitcoinExchange::exchange_header = "date,exchange_rate";
char BitcoinExchange::exchange_separator = ',';

void BitcoinExchange::load_exchange(void)
{
	exchange_file.open(exchange_file_path.c_str(), std::ios::in);
	if (exchange_file.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		std::exit(1);
	}

	std::string line;
	std::string date;
	double rate;
	while (std::getline(exchange_file, line))
	{
		if (line == exchange_header)
			continue;

		std::stringstream line_strm(line);
		std::getline(line_strm, date, exchange_separator);
		line_strm >> rate;

		if (!is_valid_date(date))
			continue;

		exchange[parse_date(date)] = rate;
	}

	exchange_file.close();
}

double BitcoinExchange::get_rate_for_date(std::string date_str)
{
	t_tm date = parse_date(date_str);

	if (before(date, get_min_date()))
		return exchange[get_min_date()];
	if (after(date, get_max_date()))
		return exchange[get_max_date()];

	std::map<t_tm, double, s_time_compare>::const_iterator it = exchange.find(date);
	while (it == exchange.end())
	{
		date = yesterday(date);
		it = exchange.find(date);
	}

	return it->second;
}

t_tm BitcoinExchange::get_min_date(void)
{
	return exchange.begin()->first;
}

t_tm BitcoinExchange::get_max_date(void)
{
	return exchange.rbegin()->first;
}

void BitcoinExchange::dump_exchange(void)
{
	std::cout << exchange_header << std::endl;

	std::map<t_tm, double, s_time_compare>::const_iterator it = exchange.begin();
	while (it != exchange.end())
	{
		std::cout << date_to_str(it->first) << "," << it->second << std::endl;
		it++;
	}
}

/******************************************************************************\
 * DATES
\******************************************************************************/

bool BitcoinExchange::is_valid_date(std::string date_str)
{
	t_tm time = {};

	char *result = strptime(date_str.c_str(), ISO_DATE_FORMAT, &time);
	if (result == NULL)
	{
		std::cout << "Error: bad input => " << date_str << std::endl;
		return false;
	}

	return true;
}

t_tm BitcoinExchange::parse_date(std::string date_str)
{
	t_tm time = {};

	strptime(date_str.c_str(), ISO_DATE_FORMAT, &time);
	return time;
}

std::string BitcoinExchange::date_to_str(t_tm date)
{
	char date_str[11];

	std::strftime(date_str, sizeof(date_str), "%Y-%m-%d", &date);
	return date_str;
}

bool BitcoinExchange::before(t_tm lhs, t_tm rhs)
{
	return std::mktime(&lhs) < std::mktime(&rhs);
}

bool BitcoinExchange::after(t_tm lhs, t_tm rhs)
{
	return std::mktime(&rhs) < std::mktime(&lhs);
}

t_tm BitcoinExchange::yesterday(t_tm date)
{
	const time_t one_day_secs = 24 * 60 * 60;

	time_t yesterday_secs = std::mktime(&date) - one_day_secs;
	date = *std::localtime(&yesterday_secs);
	return date;
}

/******************************************************************************\
 * s_time_compare
\******************************************************************************/

bool s_time_compare::operator()(const t_tm &lhs, const t_tm &rhs) const
{
	return std::mktime(const_cast<struct tm *>(&lhs)) < std::mktime(const_cast<struct tm *>(&rhs));
}

/******************************************************************************\
 * BTC VALUE
\******************************************************************************/

bool BitcoinExchange::is_valid_value(std::string value_str)
{
	if (value_str.empty())
	{
		std::cout << "Error: value can't be an empty string." << std::endl;
		return false;
	}

	double value_double = std::atof(value_str.c_str());
	if (value_double < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value_double > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

/******************************************************************************\
 * OCCF
\******************************************************************************/

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &conv)
{
	*this = conv;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &conv)
{
	(void)conv;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
