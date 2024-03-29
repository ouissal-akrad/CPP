/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:09 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 14:37:01 by ouakrad          ###   ########.fr       */
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
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::Fixed(const int val)
{
	fixed = val << this->f_bits;
	std :: cout << "Int constructor called"<< std::endl;
}
Fixed::Fixed(const float val)
{
	this->fixed= roundf(val * (1 << this->f_bits));
	std :: cout << "Float constructor called"<< std::endl;
}
Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called " << std::endl;
    fixed = obj.getRawBits();
    return(*this);
}
int Fixed::getRawBits(void) const
{
	std :: cout <<  "getRawBits member function called "<< std::endl;
	return (this->fixed);
}
//
void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

Fixed::~Fixed()
{
	std::cout <<  "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)fixed / (1 << this->f_bits));
}

int Fixed::toInt(void) const
{
	return (fixed >> this->f_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}