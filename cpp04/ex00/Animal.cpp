/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:22:25 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 16:21:11 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal : Default Constractor Called"<< std::endl;
}

Animal::Animal(std::string Type)
{
    this->type = Type;
    std::cout << "Animal : Constractor with parameters Called"<< std::endl;
}

Animal::Animal(const Animal &copy)
{
    this->type = copy.type;
    std::cout << "Animal : Copy Constractor Called"<< std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    this->type = obj.type;
    return(*this);
}

std::string Animal::getType() const
{
    return(this->type);    
}

void Animal::setType(std::string Type)
{
    this->type = Type;
}
void Animal::makeSound() const
{
    std::cout << "Animal : No sound!" <<std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal : Destractor Called" << std::endl;
}