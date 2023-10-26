/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:34 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:47:54 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal : Default Constractor Called"<< std::endl;
}

WrongAnimal::WrongAnimal(std::string Type)
{
    this->type = Type;
    std::cout << "WrongAnimal : Constractor with parameters Called"<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    this->type = copy.type;
    std::cout << "WrongAnimal : Copy Constractor Called"<< std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    this->type = obj.type;
    return(*this);
}

std::string WrongAnimal::getType() const
{
    return(this->type);    
}

void WrongAnimal::setType(std::string Type)
{
    this->type = Type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal : No sound!" <<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal : Destractor Called" << std::endl;
}