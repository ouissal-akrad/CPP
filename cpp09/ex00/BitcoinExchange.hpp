/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:02 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/29 13:49:04 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<map>
#include<string.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
class BitcoinExchange 
{
    private:
    std::map<std::string, std::string> map;

    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();  
    void go(std::string info);
    void check_lines(std::string line);
    bool  isValidDateFormat(const std::string& date);
std::string trimString(const std::string& str);
void isValidValue(const std::string &str);
double toDouble(const std::string &str);
};
#endif