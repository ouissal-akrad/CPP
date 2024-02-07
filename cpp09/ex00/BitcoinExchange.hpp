/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:02 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/07 15:50:34 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <cstddef>
# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string.h>
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
	bool isValidDateFormat(const std::string &date);
	std::string trimString(const std::string &str);
	void isValidValue(const std::string &str);
	double toDouble(const std::string &str);
};
#endif