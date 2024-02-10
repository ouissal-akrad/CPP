/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:18 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/10 16:44:25 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: No input sequence provided." << std::endl;
		return (1);
	}

	std::vector<int> sequence;
	std::deque<int> sequenceDeque;

	for (int i = 1; i < argc; ++i)
	{
		// Check if all characters in argv[i] are digits
		bool allDigits = true;
		for (char *p = argv[i]; *p != '\0'; ++p)
		{
			if (!std::isdigit(*p))
			{
				allDigits = false;
				break ;
			}
		}

		if (!allDigits)
		{
			std::cout << "Error: Non-numeric character encountered." << std::endl;
			return (1);
		}

		int num = std::atoi(argv[i]);
		if (num < 0)
		{
			std::cout << "Error: Negative number encountered." << std::endl;
			return (1);
		}
		sequence.push_back(num);
		sequenceDeque.push_back(num);
	}
	performSorting(sequence, sequenceDeque);
	return (0);
}