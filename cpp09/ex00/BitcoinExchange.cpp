/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:59 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/19 13:50:44 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
        map = obj.map;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

std::string BitcoinExchange::trimString(const std::string& str) 
{
    std::size_t firstNonSpace = str.find_first_not_of(' ');
    std::size_t lastNonSpace = str.find_last_not_of(' ');

    if (firstNonSpace == std::string::npos || lastNonSpace == std::string::npos)
        return "";
    return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);  
}

bool BitcoinExchange::isValidDateFormat(const std::string &date) 
{
    std::string newDate = trimString(date);
    if (newDate.length() != 10)
        return false;

    if (newDate[4] != '-' || newDate[7] != '-')
        return false;

    std::string year = newDate.substr(0, 4);
    std::string month = newDate.substr(5, 2);
    std::string day = newDate.substr(8, 2);

    if ((!std::all_of(year.begin(), year.end(), ::isdigit)) ||
        (!std::all_of(month.begin(), month.end(), ::isdigit)) ||
        (!std::all_of(day.begin(), day.end(), ::isdigit)))
        return false;

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
        return false;

    // Check for specific months with 30 days
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;

    // Check for February
    if (monthInt == 2) {
        // Check for leap year
        bool isLeap = ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0);
        if (dayInt > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

void BitcoinExchange::check_lines(std::string line)
{
    size_t pipe = line.find('|');
    std::string suff;
    std::string pref;

    if(pipe == std::string::npos)
    {
        std::cout << "Error: Bad input" << std::endl;
        exit(1);
    }
    suff = line.substr(0, pipe);
    pref = line.substr(pipe + 1);
    // std::cout << "suff ======> "<< suff << std::endl;
    // std::cout << "pref ======> "<< pref << std::endl;
    if(!isValidDateFormat(suff))
    {
        std::cout << "Error: Invalid date" << std::endl;
        exit(1);
    }
}

void BitcoinExchange::go(std::string info)
{
    std::ifstream   file(info);
    std::string line;
    if(!file.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        exit(1);
    }
    if (file.eof()) 
    {
        std::cout << "Error: Empty file" << std::endl;
        exit (1);
    }
    std::getline(file, line);
    if (line != "date | value") 
    {
        std::cout << "Error: invalid format" << std::endl;
        exit(1);
    }
    while(getline(file, line))
        check_lines(line);
}
BitcoinExchange::~BitcoinExchange()
{
}