/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:18 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/06 17:41:42 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: No input sequence provided." << std::endl;
		return (1);
	}

	// Create a vector to store the elements
	std::vector<int> sequence;
	std::deque<int> sequenceDeque; // Create a deque to store the same elements

	for (int i = 1; i < argc; ++i)
	{
		// Convert the argument to an integer
		int num;
		std::stringstream(argv[i]) >> num;

		// Check for negative numbers
		if (num < 0)
		{
			std::cout << "Error: Negative number encountered." << std::endl;
			return (1);
		}

		// Push the number into the vector
		sequence.push_back(num);

		// Push the same number into the deque
		sequenceDeque.push_back(num);
	}

	// Perform Ford-Johnson Merge-Insertion Sort on the vector
	performSorting(sequence, sequenceDeque);

	return (0);
}