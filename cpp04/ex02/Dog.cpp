/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:11 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/27 15:30:56 by ouakrad          ###   ########.fr       */
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
    *(this->brain) = *copy.brain;
    std::cout << "Dog : Copy Constractor Called"<< std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this == &obj)
        return *this;
    delete brain;
    this->type = obj.type;
    this->brain = new Brain();
    *(this->brain) = *(obj.brain);
    return(*this);
}

void Dog::makeSound() const
{
    std::cout<< "Dog barks" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog : Destractor Called" << std::endl;
}
std::string Dog::getType() const
{
    return(this->type);     
}
const Brain* Dog:: getBrain() const
{
	return(this->brain);
}
void Dog::setBrain(Brain brain)
{
	*this->brain = brain;
}