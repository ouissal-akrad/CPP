/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:20:39 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/25 03:22:29 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

void ScalarConverter::convert(std::string &value,char **argv)
{
	int i;
	float f;
	double d;
	try
    {
        if (strlen(argv[1]) == 1)
            to_char(argv[1][0]);
        else if (value == "-inff" || value == "+inff" || value == "nanf" || value == "-inf" || value == "+inf" || value == "nan")
        {
            std::cout << "char: impossible " << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (value == "-inf" || value == "+inf" || value == "nan")
                std::cout << "float: " << value << "f" << std::endl;
            else
                std::cout << "float: " << value << std::endl;
            std::stringstream ss(value);
            ss >> std::fixed >> d;
            std::cout << "double: " << d << std::endl;
        }
        else
        {
            std::stringstream ss(value);
            ss >> d;
            if (ss.fail())
            {
                ss.clear();
                ss.seekg(0);
                ss >> f;
                if (ss.fail())
                {
                    ss.clear();
                    ss.seekg(0);
                    ss >> i;
                    if (ss.fail())
                        std::cout << "Failed" << std::endl;
                    else
                        to_int(i);
                }
                else
                    to_float(f);
            }
            else
                to_double(d);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

ScalarConverter::~ScalarConverter()
{
}
