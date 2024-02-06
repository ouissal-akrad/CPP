/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:33:15 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/06 17:41:11 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	displaySequence(const std::vector<int> &sequence,const std::string &message)
{
	std::cout << message << ": ";
	for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
bool	comparePairs(const std::pair<int, int> &pair1, const std::pair<int,int> &pair2)
{
	return (pair1.first < pair2.first);
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
	// Handle odd number of elements
	lastElement = -1;
	if ((end - start + 1) % 2 != 0)
	{
		lastElement = c[end];
		c.erase(c.begin() + end);
	}
	// Sort pairs
	std::vector<std::pair<int, int> > vect;
	for (int i = start; i < end; i += 2)
	{
		if (c[i] < c[i + 1])
			std::swap(c[i], c[i + 1]);
		std::pair<int, int> pair = std::make_pair(c[i], c[i + 1]);
		vect.push_back(pair);
	}
	// Sort pairs based on the first element
	std::sort(vect.begin(), vect.end(), comparePairs);
	// Separate pairs into two containers
	std::vector<int> firstElements;
	std::vector<int> secondElements;
	for (size_t i = 0; i < vect.size(); ++i)
	{
		firstElements.push_back(vect[i].first);
		secondElements.push_back(vect[i].second);
	}
	// Push the first element of secondElements to the top of firstElements
    if (!secondElements.empty())
    {
        firstElements.insert(firstElements.begin(), secondElements.front());
        secondElements.erase(secondElements.begin());
    }

	if (lastElement != -1)
    	secondElements.push_back(lastElement);
	
	// Combine secondElements with firstElements using binary search
    for (size_t i = 0; i < secondElements.size(); ++i)
    {
        size_t insertionIndex = std::lower_bound(firstElements.begin(), firstElements.end(), secondElements[i]) - firstElements.begin();
        firstElements.insert(firstElements.begin() + insertionIndex, secondElements[i]);
    }
	displaySequence(firstElements, "After");
}


//with deque
void fordJohnsonMergeInsertionSortt(std::deque<int>& c, int start, int end) {
    int lastElement;

    if (start >= end)
        return; // Base case for single element or invalid range
    // Base case for two elements
    if (end - start == 1) {
        if (c[start] > c[end])
            std::swap(c[start], c[end]);
        return;
    }
    // Handle odd number of elements
    lastElement = -1;
    if ((end - start + 1) % 2 != 0) {
        lastElement = c[end];
        c.erase(c.begin() + end);
    }
    // Sort pairs
    std::vector<std::pair<int, int> > vect;
    for (int i = start; i < end; i += 2) {
        if (c[i] < c[i + 1])
            std::swap(c[i], c[i + 1]);
        std::pair<int, int> pair = std::make_pair(c[i], c[i + 1]);
        vect.push_back(pair);
    }
    // Sort pairs based on the first element
    std::sort(vect.begin(), vect.end(), comparePairs);
    // Separate pairs into two containers
    std::vector<int> firstElements;
    std::vector<int> secondElements;
    for (size_t i = 0; i < vect.size(); ++i) {
        firstElements.push_back(vect[i].first);
        secondElements.push_back(vect[i].second);
    }
    // Push the first element of secondElements to the top of firstElements
    if (!secondElements.empty()) {
        firstElements.insert(firstElements.begin(), secondElements.front());
        secondElements.erase(secondElements.begin());
    }

    if (lastElement != -1)
        secondElements.push_back(lastElement);

    // Combine secondElements with firstElements using binary search
    for (size_t i = 0; i < secondElements.size(); ++i) {
        size_t insertionIndex = std::lower_bound(firstElements.begin(), firstElements.end(), secondElements[i]) - firstElements.begin();
        firstElements.insert(firstElements.begin() + insertionIndex, secondElements[i]);
    }
}

void	performSorting(std::vector<int> sequence,std::deque<int> sequenceDeque)
{
	clock_t startVector;
	clock_t endVector;

	clock_t startDeque;
	clock_t endDeque;
	
	startVector = clock();
	displaySequence(sequence, "Before");
	fordJohnsonMergeInsertionSort(sequence, 0, sequence.size() - 1);
	endVector = clock();
	std::cout << "Time to process a range of " << sequence.size() << " element " << "with vector "<< double(endVector - startVector) / CLOCKS_PER_SEC * 1000000 << " us." << std::endl;
	//for deque
	startDeque = clock();
	fordJohnsonMergeInsertionSortt(sequenceDeque, 0, sequenceDeque.size() - 1);
	endDeque = clock();
	std::cout << "Time to process a range of " << sequence.size() << " element " << "with deque "<< double(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000 << " us." << std::endl;
}