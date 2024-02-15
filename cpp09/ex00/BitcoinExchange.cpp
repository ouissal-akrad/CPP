/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:59 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/15 23:27:47 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trimString(const std::string &str)
{
	std::size_t firstNonSpace = 0;
	std::size_t lastNonSpace = 0;
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (str[i] != ' ')
		{
			firstNonSpace = i;
			break ;
		}
	}
	for (std::string::size_type i = str.length() - 1; i > 0; --i)
	{
		if (str[i] != ' ')
		{
			lastNonSpace = i;
			break ;
		}
	}
	return (str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1));
}

bool	isAllDigits(const std::string &str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isValidDateFormat(const std::string &date)
{
	bool	isLeap;
	int		maxDaysInFebruary;

	std::string newDate = trimString(date);
	if (newDate.length() != 10 || newDate[4] != '-' || newDate[7] != '-')
		return (false);
	std::string year = newDate.substr(0, 4);
	std::string month = newDate.substr(5, 2);
	std::string day = newDate.substr(8, 2);
	if (!isAllDigits(year) || !isAllDigits(month) || !isAllDigits(day))
		return (false);
	int Iyear, Imonth, Iday;
	std::stringstream Syear(year);
	std::stringstream Smonth(month);
	std::stringstream Sday(day);
	Syear >> Iyear;
	Smonth >> Imonth;
	Sday >> Iday;
	
	if ((Iyear < 2009 || Iyear > 2022) ||
		(Imonth < 1 || Imonth > 12) ||
		(Iday < 1 || Iday > 31))
		return (false);
	
	if (Imonth == 2)
	{
		isLeap = (Iyear % 4 == 0);
		maxDaysInFebruary = 28;
		if (isLeap)
			maxDaysInFebruary = 29;
		if (Iday > maxDaysInFebruary)
			return (false);
	}

	if ((Imonth == 4 || Imonth == 6 || Imonth == 9 || Imonth == 11)
		&& Iday > 30)
		return (false);
	return (true);
}

double	toDouble(const std::string &str)
{
	double	value;

	std::stringstream ss(str);
	ss >> value;
	return (value);
}

void	isValidValue(const std::string &str)
{
	double	value;
	size_t	decimalPoint;
	bool	sign;
	size_t	startIndex;

	std::string newValue = trimString(str);
	if (std::find(newValue.begin(), newValue.end(), '.') != newValue.end())
	{
		decimalPoint = newValue.find('.');
		if (std::find(newValue.begin() + decimalPoint + 1, newValue.end(),
				'.') != newValue.end())
			throw std::invalid_argument("too many decimal points");
	}
	sign = newValue[0] == '+';
	startIndex = sign ? 1 : 0;
	for (size_t i = startIndex; i < newValue.length(); i++)
	{
		if (std::isdigit(newValue[i]) || newValue[i] == '.')
			continue ;
		else
			throw std::invalid_argument("not a digit or not a positive number => " + newValue);
	}
	value = toDouble(newValue);
	if (value < 0)
		throw std::invalid_argument("not a positive digit");
	if (value > 1000.0)
		throw std::invalid_argument("too large");
}

void	check_lines(std::string suff, std::string pref)
{
	double	rate;
	double	exchangeRate;
	double	result;
	
	suff = trimString(suff);
	pref = trimString(pref);

	std::ifstream inputFile("data.csv");
	if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "The data file is empty." << std::endl;
		exit(1);
	}
	std::string line;
	std::map<std::string, double> exchangeRates;
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			std::istringstream(rateStr) >> rate;
			exchangeRates[date] = rate;
		}
		else
			std::cout << "Error parsing line: " << line << std::endl;
	}

	std::map<std::string, double>::iterator it = exchangeRates.find(pref);
	if (it != exchangeRates.end())
	{
		exchangeRate = it->second;
		result = std::atof(suff.c_str()) * exchangeRate;
		std::cout << pref << " => " << suff << " = " << result << std::endl;
	}
	else
	{
		std::map<std::string,double>::iterator lower = exchangeRates.lower_bound(pref);
		if (lower != exchangeRates.begin())
		{
			--lower;
			exchangeRate = lower->second;
			result = std::atof(suff.c_str()) * exchangeRate;
			std::cout << pref << " => " << suff << " = " << result << std::endl;
		}
		else
			std::cout << "Error: No exchange rate found." << std::endl;
	}
}

void	go(std::string info)
{
	size_t pipe;

	std::ifstream file(info);
	std::string line;
	if (!file.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		exit(1);
	}
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: Empty file" << std::endl;
		exit(1);
	}
	if (!file)
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cout << "Error: invalid format" << std::endl;
		exit(1);
	}
	if (file.eof())
	{
		std::cout << "Error: EOF" << std::endl;
		exit(1);
	}
	while (getline(file, line))
	{
		std::string prevDate;
		pipe = line.find('|');
		std::string suff;
		std::string pref;
		if (pipe == std::string::npos)
		{
			std::cout << "Error: Bad input"
						<< " => " << line << std::endl;
			continue ;
		}
		pref = line.substr(0, pipe);
		suff = line.substr(pipe + 1);
		if (pref.empty() || suff.empty())
			std::cout << "Error: Empty or null substring encountered." << std::endl;
		if (!isValidDateFormat(pref))
		{
			std::cout << "Error: Invalid date" << std::endl;
			continue ;
		}
		try
		{
			isValidValue(suff);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			continue ;
		}
		check_lines(suff, pref);
	}
}