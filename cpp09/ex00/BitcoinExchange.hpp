/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:02 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/12 17:19:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <cstddef>
# include <cstdlib>
# include <fstream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string.h>
#include <cstdio>
#include <iostream>

std::string	trimString(const std::string &str);
void	go(std::string info);
void	check_lines(std::string suff, std::string pref);
bool	isValidDateFormat(const std::string &date);
void	isValidValue(const std::string &str);
double	toDouble(const std::string &str);
#endif