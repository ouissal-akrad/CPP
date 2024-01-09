/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:11 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/09 17:06:06 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}
Span::Span(unsigned int N)
{
	this->N = N;
}
Span::Span(const Span &copy)
{
	*this = copy;
}
Span &Span::operator=(const Span &a)
{
	if (this != &a)
	{
		this->N = a.N;
		this->v = a.v;
	}
	return (*this);
}
unsigned int Span::get_N() const
{
	return (N);
}
void Span::set_N(unsigned int n)
{
	this->N = n;
}
unsigned int Span::shortestSpan()
{
	int min = INT_MAX;
	sort(v.begin(),v.end());
	if(v.size() < 2)
		throw std::out_of_range("Cannot find span with less than two numbers.");;
	for (unsigned int i = 0 ;i < v.size() - 1; i++)
	{
		int span = abs(v[i + 1] - v[i]);
        if (min > span)
            min = span;
	}
	return(min);
}
unsigned int Span::longestSpan()
{
	if (v.size() < 2)
		throw std::runtime_error("Error: No span can be found.");
	std::sort(v.begin(), v.end());
	return (v.back() - v.front());
}
void Span::addNumber(int n)
{
	if (v.size() < N)
		v.push_back(n);
	else
		throw std::out_of_range("error");
}

void Span::addNumbers(std::vector<int>::iterator begin,std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > this->N - (unsigned int)this->v.size())
		throw std::out_of_range("vector : out of boundries insert");
	this->v.insert(v.end(), begin, end);
}
Span ::~Span()
{
}