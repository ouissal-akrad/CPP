/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:11 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 20:30:44 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog : Default Constractor Called"<< std::endl;
}

Dog::Dog(const Dog &copy)
{
    this->type = copy.type;
    std::cout << "Dog : Copy Constractor Called"<< std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    this->type = obj.type;
    return(*this);
}

void Dog::makeSound() const
{
    std::cout<< "Dog barks" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog : Destractor Called" << std::endl;
}