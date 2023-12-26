/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:02:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/26 23:53:08 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
template <typename T>
class Array
{
	T *array;
	unsigned int n;

  public:
	Array();
	Array(unsigned int);
	Array(const Array<T> &);
	Array &operator=(const Array &);
	T &operator[](unsigned int);
	int size() const;
	~Array();
};

#include "Array.tpp"
#endif