/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:36 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/02 19:56:43 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <limits>
# include <vector>
class Span
{
	unsigned int N;
	std::vector<int> v;

  public:
	Span();
	Span(unsigned int);
	Span(const Span &);
	Span &operator=(const Span &);
	void addNumber(int n);
	void addNumbers(std::vector<int>::iterator begin,std::vector<int>::iterator end);

	unsigned int get_N() const;
	void set_N(unsigned int);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	~Span();
};

#endif