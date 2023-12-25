/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:27:52 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 20:33:34 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include<iostream>
#include <cstdlib>
#include <ctime>
class Base
{
    public:
    virtual ~Base();  
};

class A : public Base{};
class B : public Base{};
class C : public Base{};
Base *generate();
void	identify(Base *p);
void	identify(Base &p);
#endif