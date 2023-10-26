/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:11 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 15:54:40 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog : Default Constractor Called"<< std::endl;
}

Dog::Dog(const Dog &copy)
{
    this->type = copy.type;
    this->brain = new Brain();
    std::cout << "Dog : Copy Constractor Called"<< std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    this->type = obj.type;
    this->brain = new Brain();
    return(*this);
}

void Dog::makeSound() const
{
    delete brain;
    std::cout<< "Dog barks" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog : Destractor Called" << std::endl;
}
const Brain* Dog:: getBrain() const
{
	return(this->brain);
}
void Dog::setBrain(Brain brain)
{
	*this->brain = brain;
}