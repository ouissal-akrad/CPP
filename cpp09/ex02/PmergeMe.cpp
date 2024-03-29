/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:33:15 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/15 21:18:16 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	displaySequence(const std::vector<int> &sequence,
						const std::string &message)
{
	std::cout << message << ": ";
	for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
bool	comparePairs(const std::pair<int, int> &pair1, const std::pair<int,
		int> &pair2)
{
	return (pair1.first < pair2.first);
}
long int	getjcob(int i)
{
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);  
	return (getjcob(i - 1) + (2 * getjcob(i - 2)));
}

void sortPairs(std::vector<std::pair<int, int> >& arr, int left, int right) 
{
    if (left >= right)
        return;

    for (int i = left; i < right; i++) 
	{
        if (comparePairs(arr[i + 1], arr[i])) 
            std::swap(arr[i], arr[i + 1]);
    }
    sortPairs(arr, left, right - 1);
}


void	fordJohnsonMergeInsertionSortVector(std::vector<int> &c, int start,
		int end, std::vector<int> &sortedSequence)
{
	int			lastElement;
	long int	breakVal;
	long int	jacobVal;

	if (start >= end)
		return ;
	if ((c.size() == 2) || (end - start == 1))
	{
		if (c[start] > c[end])
		{
			std::swap(c[start], c[end]);
			sortedSequence.push_back(c[start]);
			sortedSequence.push_back(c[end]);
		}
		else
		{
			sortedSequence.push_back(c[start]);
			sortedSequence.push_back(c[end]);
		}
		return ;
	}
	lastElement = -1;
	if ((end - start + 1) % 2 != 0)
	{
		lastElement = c[end];
		c.erase(c.begin() + end);
	}
	std::vector<std::pair<int, int> >  vect;
	for (int i = start; i < end; i += 2)
	{
		if (c[i] < c[i + 1])
			std::swap(c[i], c[i + 1]);
		std::pair<int, int> pair = std::make_pair(c[i], c[i + 1]);
		vect.push_back(pair);
	}
	sortPairs(vect, 0, vect.size() - 1);
	std::vector<int> firstElements;
	std::vector<int> secondElements;
	for (size_t i = 0; i < vect.size(); ++i)
	{
		firstElements.push_back(vect[i].first);
		secondElements.push_back(vect[i].second);
	}
	if (!secondElements.empty())
	{
		firstElements.insert(firstElements.begin(), secondElements.front());
		secondElements.erase(secondElements.begin());
	}
	std::vector<long int> jbNumbers;
	for (int i = 0; i >= 0; i++)
	{
		jbNumbers.push_back(getjcob(i));
		if (jbNumbers.back() >= (long)secondElements.size() + 1)
			break ;
	}
	breakVal = 0;
	std::vector<int>::iterator vit;
	for (int i = 3; i < (int)jbNumbers.size(); i++)
	{
		jacobVal = jbNumbers[i];
		while (jacobVal > breakVal)
		{
			if ((jacobVal) <= (long int)secondElements.size())
			{
				vit = std::lower_bound(firstElements.begin(),
						firstElements.end(), secondElements[jacobVal - 1]);
				firstElements.insert(vit, secondElements[jacobVal - 1]);
			}
			jacobVal--;
		}
		breakVal = jbNumbers[i];
	}
	if(lastElement != -1)
	{
		vit = std::lower_bound(firstElements.begin(),
						firstElements.end(),lastElement);
		firstElements.insert(vit, lastElement);
	}
	sortedSequence = firstElements;
}

void	fordJohnsonMergeInsertionSortDeque(std::deque<int> &c, int start,
		int end, std::vector<int> &sortedSequence)
{
	int			lastElement;
	long int	breakVal;
	long int	jacobVal;

	if (start >= end)
		return ;
	if (c[start] > c[end])
	{
		std::swap(c[start], c[end]);
		sortedSequence.push_back(c[start]);
		sortedSequence.push_back(c[end]);
	}
	lastElement = -1;
	if ((end - start + 1) % 2 != 0)
	{
		lastElement = c[end];
		c.erase(c.begin() + end);
	}
	std::vector<std::pair<int, int> > vect;
	for (int i = start; i < end; i += 2)
	{
		if (c[i] < c[i + 1])
			std::swap(c[i], c[i + 1]);
		std::pair<int, int> pair = std::make_pair(c[i], c[i + 1]);
		vect.push_back(pair);
	}
	sortPairs(vect, 0, vect.size() - 1); 
	std::vector<int> firstElements;
	std::vector<int> secondElements;
	for (size_t i = 0; i < vect.size(); ++i)
	{
		firstElements.push_back(vect[i].first);
		secondElements.push_back(vect[i].second);
	}
	if (!secondElements.empty())
	{
		firstElements.insert(firstElements.begin(), secondElements.front());
		secondElements.erase(secondElements.begin());
	}
	std::vector<long int> jbNumbers;
	for (int i = 0; i >= 0; i++)
	{
		jbNumbers.push_back(getjcob(i));
		if (jbNumbers.back() >= (long)secondElements.size() + 1)
			break ;
	}
	breakVal = 0;
	std::vector<int>::iterator vit;
	for (int i = 3; i < (int)jbNumbers.size(); i++)
	{
		jacobVal = jbNumbers[i];
		while (jacobVal > breakVal)
		{
			if ((jacobVal) <= (long int)secondElements.size())
			{
				vit = std::lower_bound(firstElements.begin(),
						firstElements.end(), secondElements[jacobVal - 1]);
				firstElements.insert(vit, secondElements[jacobVal - 1]);
			}
			jacobVal--;
		}
		breakVal = jbNumbers[i];
	}
	if(lastElement != -1)
	{
		vit = std::lower_bound(firstElements.begin(),
						firstElements.end(),lastElement);
		firstElements.insert(vit, lastElement);
	}
	sortedSequence = firstElements;
}

void	performSorting(std::vector<int> sequence, std::deque<int> sequenceDeque)
{
	clock_t startVector;
	clock_t endVector;

	clock_t startDeque;
	clock_t endDeque;

	std::vector<int> sortedSequence;
	if (sequence.size() == 1 || sequenceDeque.size() == 1)
	{
		std::cout << "We can't accept one digit" << std::endl;
		return ;
	}
	startVector = clock();
	displaySequence(sequence, "Before");
	fordJohnsonMergeInsertionSortVector(sequence, 0, sequence.size() - 1,
			sortedSequence);
	displaySequence(sortedSequence, "After");
	endVector = clock();
	std::cout << "Time to process a range of " << sortedSequence.size() << " element "
				<< "with vector " << std::setprecision(5) << double(endVector - startVector) / 1000000 << " us." << std::endl;
	startDeque = clock();
	fordJohnsonMergeInsertionSortDeque(sequenceDeque, 0, sequenceDeque.size()
			- 1, sortedSequence);
	endDeque = clock();
	std::cout << "Time to process a range of " << sortedSequence.size() << " element " 	<< "with deque " << std::setprecision(5) << double(endDeque - startDeque) / 1000000 << " us." << std::endl;
}