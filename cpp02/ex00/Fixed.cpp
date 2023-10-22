/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:09 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 14:02:50 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
	this->fixed  = 0;
	std :: cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &obj)
{
	this->fixed = obj.fixed;
	std :: cout << "Copy constructor called"<< std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called " << std::endl;
    fixed = obj.getRawBits();
    return(*this);
}

int Fixed :: getRawBits(void) const
{
	std :: cout <<  "getRawBits member function called "<< std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

Fixed::~Fixed()
{
	std :: cout <<  "Destructor called" << std::endl;
}