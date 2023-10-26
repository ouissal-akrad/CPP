/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:22:25 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 16:22:36 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"

AAnimal::AAnimal()
{
    this->type = "Animal";
    std::cout << "AAnimal : Default Constractor Called"<< std::endl;
}

AAnimal::AAnimal(std::string Type)
{
    this->type = Type;
    std::cout << "AAnimal : Constractor with parameters Called"<< std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    this->type = copy.type;
    std::cout << "AAnimal : Copy Constractor Called"<< std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
    this->type = obj.type;
    return(*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal : Destractor Called" << std::endl;
}