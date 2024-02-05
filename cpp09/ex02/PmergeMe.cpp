/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:33:15 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/05 17:54:02 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	displaySequence(const std::vector<int> &sequence,
						const std::string &message)
{
	std::cout << message << ": ";
	for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	displayTiming(const std::string &containerName,
					const clock_t &startTime,
					const clock_t &endTime)
{
	std::cout << "Time to process a range of " << containerName << " : "
				<< double(endTime - startTime) / CLOCKS_PER_SEC
					* 1000000 << " us." << std::endl;
}

int	findMedian(const std::list<int> &indices)
{
	std::vector<int> temp(indices.begin(), indices.end());
	std::sort(temp.begin(), temp.end());
	return (temp[temp.size() / 2]);
}

int	customPartition(std::vector<int> &c, int start, int end, int pivotIndex)
{
	int	storeIndex;

	std::swap(c[pivotIndex], c[end]); // Move pivot to end
	storeIndex = start;
	for (int i = start; i < end; i++)
	{
		if (c[i] < c[end])
		{
			std::swap(c[i], c[storeIndex]);
			storeIndex++;
		}
	}
	std::swap(c[storeIndex], c[end]); // Move pivot to its final place
	return (storeIndex);
}
//Function to check for duplicates in the vector
bool	hasDuplicates(const std::vector<int> &c)
{
	std::vector<int> sortedCopy = c;
	// Create a copy to avoid modifying the original vector
	std::sort(sortedCopy.begin(), sortedCopy.end());
	for (size_t i = 1; i < sortedCopy.size(); ++i)
	{
		if (sortedCopy[i] == sortedCopy[i - 1])
		{
			return (true); // Duplicate found
		}
	}
	return (false); // No duplicates found
}

void	fordJohnsonMergeInsertionSort(std::vector<int> &c, int start, int end)
{
	int	lastElement;

	if (start >= end)
		return ; // Base case for single element or invalid range
	// Base case for two elements
	if (end - start == 1)
	{
		if (c[start] > c[end])
			std::swap(c[start], c[end]);
		return ;
	}
	// // Handle odd number of elements
	lastElement = 0;
	if ((end - start + 1) % 2 != 0)
		lastElement = c[end];
	std::cout << "lastElement " << lastElement << std::endl;
	// Sort pairs
	std::vector<std::pair<int, int>> vect;
	for (int i = start; i < end; i += 2)
	{
		if (c[i] > c[i + 1])
			std::swap(c[i], c[i + 1]);
		std::pair<int, int> pair = std::make_pair(c[i], c[i + 1]);
		vect.push_back(pair);
	}
	for (std::vector<std::pair<int,
			int>>::const_iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void	performSorting(std::vector<int> sequence)
{
	clock_t startTime;
	clock_t endTime;

	startTime = clock();
	fordJohnsonMergeInsertionSort(sequence, 0, sequence.size() - 1);
	endTime = clock();
	// displaySequence(sequence, "After");
	// displayTiming("std::vector", startTime, endTime);
}