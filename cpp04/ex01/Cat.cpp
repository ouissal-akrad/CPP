/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:47:31 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 21:39:13 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat : Default Constractor Called"<< std::endl;
}

Cat::Cat(const Cat &copy)
{
    this->type = copy.type;
    this->brain = new Brain();
    std::cout << "Cat : Copy Constractor Called"<< std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    this->type = obj.type;
    this->brain = new Brain();
    return(*this); 
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat : Destractor Called" << std::endl;
}

Brain *Cat::getBrain() const
{
	return(this->brain);
}

void Cat::setBrain(Brain brain)
{
	*this->brain = brain;
}
