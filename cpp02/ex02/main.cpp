/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:09:33 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 14:52:12 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
	// Exemple
	// Fixed a(5.0f);
	// Fixed b(10.0f);
	// if (a < b)
	// 	std::cout << "a is less than b" << std::endl;
	// else
	// 	std::cout << "a is not less than b" << std::endl;
	//if i don't implement the operator
	// if (a.getRawBits() < b.getRawBits())
	// 	std::cout << "a is less than b" << std::endl;
	// else
	// 	std::cout << "a is not less than b" << std::endl;
	// return (0);
}
