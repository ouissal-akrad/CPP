/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:59 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/10 15:39:53 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdio>
#include <iostream>

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
	//here cpp11
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
	// If there's more than one decimal point, throw an error
	if (std::find(newValue.begin(), newValue.end(), '.') != newValue.end())
	{
		decimalPoint = newValue.find('.');
		if (std::find(newValue.begin() + decimalPoint + 1, newValue.end(),
				'.') != newValue.end())
			throw std::invalid_argument("too many decimal points");
	}
	// If there's a +
	sign = newValue[0] == '+';
	for (size_t i = sign ? 1 : 0; i < newValue.length(); i++)
	{
		if (std::isdigit(newValue[i]) || newValue[i] == '.')
			continue ;
		throw std::invalid_argument("not a digit => " + newValue);
	}
	value = toDouble(newValue);
	if (value < 0)
		throw std::invalid_argument("not a positive digit");
	if (value > 1000.0)
		throw std::invalid_argument("too large");
}

void BitcoinExchange::check_lines(std::string suff, std::string pref)
{
	double	rate;
	double	exchangeRate;
	double	result;

	std::ifstream inputFile("data.csv");
	// Check if the file is empty
	if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "The data file is empty." << std::endl;
		return ;
	}
	std::string line2;
	std::map<std::string, double> exchangeRates;
	while (std::getline(inputFile, line2))
	{
		std::istringstream iss(line2);
		std::string date;
		std::string rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			std::istringstream(rateStr) >> rate;
			exchangeRates[date] = rate;
		}
		else
			std::cout << "Error parsing line: " << line2 << std::endl;
	}
	std::map<std::string, double>::iterator it2 = exchangeRates.find(pref);
	if (it2 != exchangeRates.end())
	{
		exchangeRate = it2->second;
		result = std::atof(suff.c_str()) * exchangeRate;
		std::cout << pref << "=>" << suff << " = " << result << std::endl;
	}
	else
	{
		std::map<std::string,
			double>::iterator lower = exchangeRates.lower_bound(pref);
		if (lower != exchangeRates.begin())
		{
			--lower;
			exchangeRate = lower->second;
			result = std::atof(suff.c_str()) * exchangeRate;
			std::cout << pref << "=>" << suff << " = " << result << std::endl;
		}
		else
			std::cout << "Error: No exchange rate found." << std::endl;
	}
}

bool isWhitespaceOrEmpty(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isspace(*it)) {
            return false;
        }
    }
    return true;
}

void BitcoinExchange::go(std::string info)
{
		size_t pipe;

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
	if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return ;
    }
	while (getline(file, line))
	{
		std::string prevDate;
		pipe = line.find('|');
		std::string suff;
		std::string pref;
		if (pipe == std::string::npos)
		{
			std::cout << "Error: Bad input" << " => " << line << std::endl;
			continue ;
		}
		pref = line.substr(0, pipe);
		suff = line.substr(pipe + 1);
		if (pref.empty() || suff.empty())
		{
			std::cout << "Error: Empty or null substring encountered." << std::endl;
			return ;
		}
		if (!isValidDateFormat(pref))
		{
			std::cout << "Error: Invalid date" << std::endl;
			continue;
		}
		try
		{
			isValidValue(suff);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			continue;
		}
		check_lines(suff, pref);
	}
}
BitcoinExchange::~BitcoinExchange()
{
}