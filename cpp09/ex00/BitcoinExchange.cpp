/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:59 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/31 16:17:44 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		map = obj.map;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

std::string BitcoinExchange::trimString(const std::string &str)
{
	std::size_t firstNonSpace;
	std::size_t lastNonSpace;
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (str[i] != ' ')
		{
			firstNonSpace = i;
			break ;
		}
	}
	// Find last non-space character
	for (std::string::size_type i = str.length() - 1; i > 0; --i)
	{
		if (str[i] != ' ')
		{
			lastNonSpace = i;
			break ;
		}
	}
	if (firstNonSpace == std::string::npos || lastNonSpace == std::string::npos)
		return ("");
	return (str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1));
}

bool BitcoinExchange::isValidDateFormat(const std::string &date)
{
	bool	isLeap;

	std::string newDate = trimString(date);
	if (newDate.length() != 10)
		return (false);
	if (newDate[4] != '-' || newDate[7] != '-')
		return (false);
	std::string year = newDate.substr(0, 4);
	std::string month = newDate.substr(5, 2);
	std::string day = newDate.substr(8, 2);
	//here
	if ((!std::all_of(year.begin(), year.end(), ::isdigit)) ||
		(!std::all_of(month.begin(), month.end(), ::isdigit)) ||
		(!std::all_of(day.begin(), day.end(), ::isdigit)))
		return (false);
	int yearInt, monthInt, dayInt;
	std::stringstream ssYear(year);
	std::stringstream ssMonth(month);
	std::stringstream ssDay(day);
	ssYear >> yearInt;
	ssMonth >> monthInt;
	ssDay >> dayInt;
	if ((yearInt < 2009 || yearInt > 2022) ||
		(monthInt < 1 || monthInt > 12) ||
		(dayInt < 1 || dayInt > 31))
		return (false);
	// Check for specific months with 30 days
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)
		&& dayInt > 30)
		return (false);
	// Check for February
	if (monthInt == 2)
	{
		// Check for leap year
		isLeap = ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt
				% 400 == 0);
		if (dayInt > (isLeap ? 29 : 28))
			return (false);
	}
	return (true);
}

double BitcoinExchange::toDouble(const std::string &str)
{
	double	value;

	std::stringstream ss(str);
	ss >> value;
	return (value);
}

void BitcoinExchange::isValidValue(const std::string &str)
{
	double	value;
	size_t	decimalPoint;
	bool	sign;

	std::string newValue = trimString(str);
	// std::cout << newValue << std::endl;
	try
	{
		// If there's more than one decimal point, throw an error
		if (std::find(newValue.begin(), newValue.end(), '.') != newValue.end())
		{
			decimalPoint = newValue.find('.');
			if (std::find(newValue.begin() + decimalPoint + 1, newValue.end(),
					'.') != newValue.end())
				throw std::invalid_argument("too many decimal points");
		}
		// If there's a + or -
		sign = newValue[0] == '+';
		for (size_t i = sign ? 1 : 0; i < newValue.length(); i++)
		{
			if (std::isdigit(newValue[i]) || newValue[i] == '.')
				continue ;
			throw std::invalid_argument("not a digit => " + newValue);
		}
		value = toDouble(newValue);
	}
	catch (std::exception &e)
	{
		throw std::invalid_argument("not a digit => " + newValue);
	}
	if (value < 0)
		throw std::invalid_argument("not a positive digit");
	if (value > 1000.0)
		throw std::invalid_argument("too large");
}

void BitcoinExchange::check_lines(std::string line)
{
	size_t	pipe;
	std::string	prevDate;

	pipe = line.find('|');
	std::string suff;
	std::string pref;
	if (pipe == std::string::npos)
	{
		std::cout << "Error: Bad input" << std::endl;
		exit(1);
	}
	pref = line.substr(0, pipe);
	suff = line.substr(pipe + 1);
	// std::cout << "pref ======> "<< pref << std::endl;
	// std::cout << "suff ======> "<< suff << std::endl;
	if (!isValidDateFormat(pref))
	{
		std::cout << "Error: Invalid date" << std::endl;
		exit(1);
	}
	isValidValue(pref);
	// std::map<std::string, std::string>::iterator it;
	// prevDate = pref;
	// it = map.find(pref);
	// while (it == map.end())
	// {
	// 	const std::string &currentDate = prevDate;
	// 	// prevDate = findTheClosest(currentDate);
	// 	it = map.find(prevDate);
	// }
	// std::cout << pref << " => " << suff << " = " << toDouble(it->second) * toDouble(suff) << std::endl;
}

void BitcoinExchange::go(std::string info)
{
	std::ifstream file(info);
	std::string line;
	if (!file.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		exit(1);
	}
	if (file.eof())
	{
		std::cout << "Error: Empty file" << std::endl;
		exit(1);
	}
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cout << "Error: invalid format" << std::endl;
		exit(1);
	}
	while (getline(file, line))
		check_lines(line);
}
BitcoinExchange::~BitcoinExchange()
{
}