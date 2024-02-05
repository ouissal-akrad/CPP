/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:20 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/05 15:51:04 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
void displaySequence(const std::vector<int> &sequence, const std::string &message);
void displayTiming(const std::string &containerName, const clock_t &startTime, const clock_t &endTime);
int findMedian(const std::list<int> &indices);
int customPartition(std::vector<int> &c, int start, int end, int pivotIndex);
void fordJohnsonMergeInsertionSort(std::vector<int> &c, int start, int end);
void performSorting(std::vector<int> sequence);
bool	hasDuplicates(const std::vector<int> &c);
#endif