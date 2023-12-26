/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:06:43 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/26 23:50:28 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Default constructor called" << std::endl;
	this->array = new T[0];
}
template <typename T>
Array<T>::Array(unsigned int  n)
{
	std::cout << "Constructor with parameters called" << std::endl;
	this->n = n;
	this->array = new T[this->n];
}
template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	*this = copy;
}template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= n)
		throw std::exception();
	return(this->array[index]);
}
template <typename T>
Array<T> &Array<T>::operator=(const Array &a)
{
	if(this != &a)
	{
		this->n = a.n;
		this->array = new T[this->n];
		std::copy(a.array, a.array + size(), this->array);
	}
	return(*this);
}
template <typename T>
int Array<T>::size() const
{
	return(this->n);
}
template <typename T> 
Array<T>::~Array()
{
	delete array;
	std::cout << "Destructor called" << std::endl;
}