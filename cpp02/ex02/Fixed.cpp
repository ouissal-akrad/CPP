/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:08:47 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/21 18:19:33 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	this->fixed  = 0;
}

// Fixed::Fixed(const Fixed &obj)
// {
// 	this->fixed = obj.fixed;
// }

Fixed ::Fixed(const int fixed)
{
	this->fixed = fixed << this->f_bits;
}
Fixed :: Fixed(const float fixed)
{
	this->fixed = roundf(fixed * (1 << this->f_bits));
}
		
Fixed :: Fixed(const Fixed &p)
{
	this->fixed = p.fixed;
}
Fixed Fixed :: operator =(const Fixed &p)
{
	this->fixed = p.fixed;
	return(p);
}
int Fixed :: getRawBits( void ) const
{
	return (this->fixed);
}
void Fixed :: setRawBits( int const raw )
{
	this->fixed = raw;
}

float Fixed :: toFloat( void ) const
{
	return ((float )this->fixed / (1 << this->f_bits));
}
int Fixed :: toInt( void ) const
{
	return (this->fixed >> this->f_bits);
}
		
Fixed :: ~Fixed()
{
	
}

bool Fixed ::  operator <(const Fixed &rh) const
{
	return(this->fixed < rh.getRawBits());
}
bool Fixed ::  operator >(const Fixed &rh) const
{
	return(this->fixed > rh.getRawBits());
}
bool Fixed ::  operator <=(const Fixed &rh) const
{
	return(this->fixed <= rh.getRawBits());
}
bool Fixed ::  operator >=(const Fixed &rh) const
{
	return(this->fixed >= rh.getRawBits());
}
bool Fixed ::  operator ==(const Fixed &rh) const
{
	return(this->fixed == rh.getRawBits());
}
bool Fixed ::  operator !=(const Fixed &rh) const
{
	return(this->fixed != rh.getRawBits());
}
Fixed Fixed ::  operator +(const Fixed &rh) const
{
	Fixed s;
	s.fixed = this->fixed + rh.getRawBits();
	return(s);
}
Fixed Fixed ::  operator -(const Fixed &rh) const
{
	Fixed s;
	s.fixed = this->fixed - rh.getRawBits();
	return(s);
}
Fixed Fixed ::  operator *(const Fixed &rh) const
{
	Fixed s;

	s.fixed = (this->toFloat() * rh.toFloat()) * (1 << this->f_bits);
	return(s);
}
Fixed Fixed ::  operator /(const Fixed &rh) const
{
	Fixed s;
	s.fixed = (this->toFloat() / rh.toFloat()) * (1 << this->f_bits);
	return(s);
}

Fixed Fixed :: operator ++(int)
{
	Fixed	tmp;
	tmp.fixed = this->fixed;
	fixed++;
	return(tmp);
}
Fixed& Fixed :: operator ++(void)
{
	fixed++;
	return(*this);
}
Fixed Fixed :: operator --(int)
{
	Fixed	tmp;
	tmp.fixed = this->fixed;
	fixed--;
	return(tmp);
}
Fixed& Fixed :: operator --(void)
{
	fixed--;
	return(*this);
}

const Fixed Fixed:: min(const Fixed &a, const Fixed &b)
{
	if (a<b)
		return(a);
	else
		return(b);
}

Fixed Fixed:: min(Fixed &a, Fixed &b)
{
	if (a<b)
		return(a);
	else
		return(b);
}
const Fixed Fixed:: max(const Fixed &a, const Fixed &b)
{
	if(a>b)
		return(a);
	else
		return(b);
}
Fixed Fixed:: max(Fixed &a, Fixed &b)
{
	if(a.getRawBits() > b.getRawBits())
		return(a);
	else
		return(b);
}
std ::ostream &operator << (std :: ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}