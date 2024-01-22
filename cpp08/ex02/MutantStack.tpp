/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:20:33 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/18 12:49:38 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>()
{
}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(MutantStack const &obj): std::stack<T, Container>(obj)
{
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <class T, class Container>
MutantStack<T, Container> &MutantStack<T,Container>::operator=(MutantStack const &obj)
{
	if (this != &obj)
		std::stack<T, Container>::operator=(obj);
	return (*this);
}

template <class T, class Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <class T, class Container>
typename Container::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}