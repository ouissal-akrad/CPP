/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:47:31 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:52:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat : Default Constractor Called"<< std::endl;
}

Cat::Cat(const Cat &copy)
{
    this->type = copy.type;
    std::cout << "Cat : Copy Constractor Called"<< std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    this->type = obj.type;
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat : Destractor Called" << std::endl;
}
