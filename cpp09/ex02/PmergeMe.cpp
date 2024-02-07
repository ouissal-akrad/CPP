/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:33:15 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/07 15:49:07 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void displaySequence(const std::vector<int> &sequence, const std::string &message)
{
    std::cout << message << ": ";
    for (size_t i = 0; i < sequence.size(); ++i)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;
}

bool	comparePairs(const std::pair<int, int> &pair1, const std::pair<int, int> &pair2)
{
	return (pair1.first < pair2.first);
}
long int getjcob(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return getjcob(i - 1) + (2 * getjcob(i - 2));
}
void fordJohnsonMergeInsertionSort(std::vector<int> &c, int start, int end)
{
    int lastElement;
    // size_t insertionIndex;

    if (start >= end)
        return; // Base case for single element or invalid range
    // Base case for two elements
    if (end - start == 1)
    {
        if (c[start] > c[end])
            std::swap(c[start], c[end]);
        return;
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
    // Jacobsthal-Lucas numbers
    std::vector<long int> jbNumbers;
    for (int i = 0; i >= 0; i++)
    {
        jbNumbers.push_back(getjcob(i));
        if (jbNumbers.back() >= (long)secondElements.size() + 1)
            break;
    }
    // Combine secondElements with firstElements using binary search
    long int breakVal = 0;
    std::vector< int>::iterator vit;
    for (int i = 3; i < (int)jbNumbers.size(); i++)
    {
        long int jacobVal = jbNumbers[i];
        while (jacobVal > breakVal)
        {
            if ((jacobVal) <= (long int)secondElements.size())
            {
                vit = std::lower_bound(firstElements.begin(), firstElements.end(), secondElements[jacobVal - 1]);
                firstElements.insert(vit, secondElements[jacobVal - 1]);
            }
            jacobVal--;
        }
        breakVal = jbNumbers[i];
    }
    displaySequence(firstElements, "After");
}
//with deque
void	fordJohnsonMergeInsertionSortt(std::deque<int> &c, int start, int end)
{
	int		lastElement;

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
	 // Jacobsthal-Lucas numbers
    std::vector<long int> jbNumbers;
    for (int i = 0; i >= 0; i++)
    {
        jbNumbers.push_back(getjcob(i));
        if (jbNumbers.back() >= (long)secondElements.size() + 1)
            break;
    }
	// Combine secondElements with firstElements using binary search
    long int breakVal = 0;
    std::vector< int>::iterator vit;
    for (int i = 3; i < (int)jbNumbers.size(); i++)
    {
        long int jacobVal = jbNumbers[i];
        while (jacobVal > breakVal)
        {
            if ((jacobVal) <= (long int)secondElements.size())
            {
                vit = std::lower_bound(firstElements.begin(), firstElements.end(), secondElements[jacobVal - 1]);
                firstElements.insert(vit, secondElements[jacobVal - 1]);
            }
            jacobVal--;
        }
        breakVal = jbNumbers[i];
    }
}

void	performSorting(std::vector<int> sequence, std::deque<int> sequenceDeque)
{
	clock_t startVector;
	clock_t endVector;

	clock_t startDeque;
	clock_t endDeque;

	startVector = clock();
	displaySequence(sequence, "Before");
	fordJohnsonMergeInsertionSort(sequence, 0, sequence.size() - 1);
	endVector = clock();
	std::cout << "Time to process a range of " << sequence.size() << " element " << "with vector " << double(endVector - startVector) / CLOCKS_PER_SEC * 1000000 << " us." << std::endl;
	//for deque
	startDeque = clock();
	fordJohnsonMergeInsertionSortt(sequenceDeque, 0, sequenceDeque.size() - 1);
	endDeque = clock();
	std::cout << "Time to process a range of " << sequence.size() << " element " << "with deque " << double(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000 << " us." << std::endl;
}