/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:58:03 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 11:00:23 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int fixed;
        static const int f_bits = 8;
    public :
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed &operator =(const Fixed &);
		bool operator <(const Fixed &) const;
		bool operator >(const Fixed &) const;
		bool operator <=(const Fixed &) const;
		bool operator >=(const Fixed &) const;
		bool operator ==(const Fixed &) const;
		bool operator !=(const Fixed &) const;
		Fixed operator +(const Fixed &) const;
		Fixed operator -(const Fixed &) const;
		Fixed operator *(const Fixed &) const;
		Fixed operator /(const Fixed &) const;
		Fixed operator ++(int);
		Fixed& operator ++(void);
		Fixed operator --(int);
		Fixed& operator --(void);
		static const Fixed min(const Fixed &, const Fixed &);
		static Fixed min(Fixed &, Fixed &);
		static const Fixed max(const Fixed &, const Fixed &);
		static Fixed max(Fixed &, Fixed &);
		~Fixed();
};
std::ostream &operator << (std::ostream &out, const Fixed &f);
#endif
