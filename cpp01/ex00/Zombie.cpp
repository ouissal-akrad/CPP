/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:08:52 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 22:32:24 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << name << ": Destructor Called" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}