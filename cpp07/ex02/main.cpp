/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:07:02 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/27 16:04:55 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	// Test the default constructor
	Array<int> array1;
	std::cout << "Size of array1: " << array1.size() << std::endl;

	// Test the constructor with parameters
	Array<double> array2(5);
	std::cout << "Size of array2: " << array2.size() << std::endl;

	// Test the copy constructor
	Array<double> array3 = array2;
	std::cout << "Size of array3: " << array3.size() << std::endl;

	// Test the subscript operator
	array2[0] = 1.23;
	array2[1] = 2.34;
	array2[2] = 3.45;
	std::cout << "Elements of array2: ";
	for (int i = 0; i < array2.size(); i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;
	// Test assignment operator
	Array<double> array4;
	array4 = array2;
	std::cout << "Size of array4: " << array4.size() << std::endl;
	// Test out of bounds access
	try
	{
		std::cout << array2[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}