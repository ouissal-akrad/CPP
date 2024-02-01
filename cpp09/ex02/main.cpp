/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:34:41 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/01 17:34:42 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>

void	displaySequence(const std::vector<int> &sequence)
{
	std::cout << "Before: ";
	std::copy(sequence.begin(), sequence.end(),std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}


int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: No input sequence provided." << std::endl;
		return (1);
	}

	std::vector<int> sequence;
	std::string arg;
	std::istringstream iss;

	for (int i = 1; i < argc; ++i)
	{
		arg = argv[i];
		iss.str(arg);
		int num;
		while (iss >> num)
		{
			if (num < 0)
			{
				std::cout << "Error: Negative number encountered." << std::endl;
				return (1);
			}
			sequence.push_back(num);
		}
		iss.clear();
	}

	displaySequence(sequence);

	std::vector<int> sequenceCopy = sequence;
	clock_t startTime = clock();
    //sort
	return (0);
}