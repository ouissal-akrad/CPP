/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:18:23 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 17:00:12 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER
#include <iostream>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(std::string &value,char **argv);
};
void to_char(char c);
void to_float(float f);
void to_int(int i);
void to_double(double d);
#endif