/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:20 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/12 17:14:20 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <sstream>
#include <iomanip>

void    displaySequence(const std::vector<long> &sequence, const std::string &message);
void    displayTiming(const std::string &containerName, const clock_t &startTime, const clock_t &endTime);
void    fordJohnsonMergeInsertionSortDeque(std::deque<int> &c, int start, int end, std::vector<int>& sortedSequence);
void    fordJohnsonMergeInsertionSortVector(std::vector<int> &c, int start, int end, std::vector<int>& sortedSequence);
void    performSorting(std::vector<int> sequence,std::deque<int> sequenceDeque);
bool	hasDuplicates(const std::vector<int> &c);
#endif