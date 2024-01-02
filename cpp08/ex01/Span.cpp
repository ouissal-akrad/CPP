/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:11 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/02 19:56:15 by ouakrad          ###   ########.fr       */
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
	unsigned int	minSpan;
	unsigned int	span;

	if (v.size() <= 1)
		throw std::logic_error("Cannot find span with less than two numbers.");
	std::sort(v.begin(), v.end());
	minSpan = static_cast<unsigned int>(v[1] - v[0]);
	for (size_t i = 2; i < v.size(); ++i)
	{
		span = static_cast<unsigned int>(v[i] - v[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
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