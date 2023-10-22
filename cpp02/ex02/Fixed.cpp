/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:08:47 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 14:55:29 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed = 0;
	std ::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int val)
{
	fixed = val << this->f_bits;
	std ::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float val)
{
	this->fixed = roundf(val * (1 << this->f_bits));
	std::cout << "Float constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called " << std::endl;
	fixed = obj.getRawBits();
	return (*this);
}
int Fixed::getRawBits(void) const
{
	std ::cout << "getRawBits member function called " << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)fixed / (1 << this->f_bits));
}

int Fixed::toInt(void) const
{
	return (fixed >> this->f_bits);
}

std ::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

bool Fixed::operator<(const Fixed &val) const
{
	return (this->fixed < val.fixed);
}
bool Fixed::operator>(const Fixed &val) const
{
	return (this->fixed > val.fixed);
}
bool Fixed::operator<=(const Fixed &val) const
{
	return (this->fixed <= val.fixed);
}
bool Fixed::operator>=(const Fixed &val) const
{
	return (this->fixed >= val.fixed);
}
bool Fixed::operator==(const Fixed &val) const
{
	return (this->fixed == val.fixed);
}
bool Fixed::operator!=(const Fixed &val) const
{
	return (this->fixed != val.fixed);
}
Fixed Fixed::operator+(const Fixed &val) const
{
	Fixed p;
	p.fixed = this->fixed + val.fixed;
	return (p);
}
Fixed Fixed::operator-(const Fixed &val) const
{
	Fixed s;
	s.fixed = this->fixed - val.fixed;
	return (s);
}
Fixed Fixed::operator*(const Fixed &val) const
{
	Fixed eg;
	eg.fixed = (this->toFloat() * val.toFloat()) * (1 << this->f_bits);
	return (eg);
}
Fixed Fixed::operator/(const Fixed &val) const
{
	if (val.fixed == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(); 
	}
	Fixed div;
    return(div.fixed = roundf(((float)fixed / val.fixed) * (1 << f_bits)), div);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp;

	tmp.fixed = this->fixed;
	fixed++;
	return (tmp);
}

Fixed &Fixed::operator++(void)
{
	fixed++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp;

	tmp.fixed = this->fixed;
	fixed--;
	return (tmp);
}
Fixed &Fixed::operator--(void)
{
	fixed--;
	return (*this);
}

const Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
const Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}