/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:05:40 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 16:56:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void to_char(char c)
{
	if(isdigit(c))
	{
		std ::cout <<"char: Non displayable "<< std::endl;
		std ::cout <<"int: " << static_cast<int>(c) - 48 << std::endl;
		std ::cout <<"float: "  << std::setprecision(1) << std::fixed << static_cast<float>(c) - 48 << "f"<< std::endl;
		std ::cout <<"double: "  << std::setprecision(1) << std::fixed << static_cast<double>(c) - 48 << std::endl;
	}
	else
	{
		std ::cout <<"char: '"<< c << "'" << std::endl;
		std ::cout <<"int: " << static_cast<int>(c) << std::endl;
		std ::cout <<"float: "  << std::setprecision(1) << std::fixed << static_cast<float>(c) << "f"<< std::endl;
		std ::cout <<"double: "  << std::setprecision(1) << std::fixed << static_cast<double>(c) << std::endl;
	}
}
void to_int(int i)
{
	if (isprint(i))
		std ::cout <<"char: '"<< static_cast<char>(i) <<"'"<< std::endl;
	else
		std ::cout <<"char: Non displayable"<< std::endl;
	std ::cout <<"int: " << i << std::endl;
	std ::cout <<"float: "  << std::setprecision(1) << std::fixed << static_cast<float>(i) << "f"<< std::endl;
	std ::cout <<"double: " << static_cast<double>(i) << std::endl;
}
void to_float(float f)
{
	if (isprint(f))
		std ::cout <<"char: '"<< static_cast<char>(f) << "'"<< std::endl;
	else
		std ::cout <<"char: Non displayable "<< std::endl;
	std ::cout <<"int: " << static_cast<int>(f) << std::endl;
	if (static_cast<int>(f)%2 == 0)
		std ::cout <<"float: "  << std::setprecision(1) << std::fixed << f << "f"<< std::endl;
	else 
		std ::cout <<"float: " << f << "f"<< std::endl;
	if (static_cast<int>(f)%2 == 0)
		std ::cout <<"double: "  << std::setprecision(1) << std::fixed << static_cast<double>(f)<< std::endl;
	else 
		std ::cout <<"double: " << static_cast<double>(f) << std::endl;
}
void to_double(double d)
{
	if (isprint(d))
		std ::cout <<"char: '"<< static_cast<char>(d) << "' "<<std::endl;
	else
		std ::cout <<"char: Non displayable"<< std::endl;
	std ::cout <<"int: " << static_cast<int>(d) << std::endl;
		if (static_cast<int>(d) % 2 == 0)
		std ::cout <<"float: "  << std::setprecision(1) << std::fixed << static_cast<float>(d) <<"f"<< std::endl;
	else 
		std ::cout <<"float: " << static_cast<float>(d) << "f"<< std::endl;
	if (static_cast<int>(d) % 2 == 0)
		std ::cout <<"double: "  << std::setprecision(1) << std::fixed << d << std::endl;
	else 
		std ::cout <<"double: " << d << std::endl;
}

int main(int argc, char **argv)
{
	
	std::string value;
	if(argc != 2) 
	{
		std::cout << "Invalid args" << std::endl;
		return 1;		
	}
	value = argv[1];
    ScalarConverter::convert(value,argv);
    return 0;
}