/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:18 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/06 16:05:25 by ouakrad          ###   ########.fr       */
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

	std::vector<int> sequence;
	std::string arg;
	std::stringstream ss(arg);
	for (int i = 1; i < argc; ++i)
	{
		arg = argv[i];
		std::stringstream ss(arg);
		int num;
		if (!(ss >> num) || !ss.eof())
		{
			std::cout << "Error: Invalid number encountered." << std::endl;
			return (1);
		}
		if (num < 0)
		{
			std::cout << "Error: Negative number encountered." << std::endl;
			return (1);
		}
		sequence.push_back(num);
	}
	// Check for duplicates before proceeding
	if (hasDuplicates(sequence))
	{
		std::cout << "Error: Duplicate elements found." << std::endl;
		return (1);
	}
	displaySequence(sequence, "Before");

	// Make a copy to keep the original sequence
	std::vector<int> sequenceCopy = sequence;

	// Perform Ford-Johnson Merge-Insertion Sort
	performSorting(sequenceCopy);

	return (0);
}