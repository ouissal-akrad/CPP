/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:19:19 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/09 20:24:48 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include<iostream>
#include <deque>
#include <stack>
template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        MutantStack(MutantStack const &obj);
        ~MutantStack();
        MutantStack &operator=(MutantStack const &obj);
        typedef typename Container::iterator iterator;
        iterator begin();
        iterator end();
};
#include "MutantStack.tpp"
#endif