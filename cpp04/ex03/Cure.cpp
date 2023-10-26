/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:00:59 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 18:45:31 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
    std::cout << "Cure : Default Constractor Called"<< std::endl;
}
Cure::Cure(const Cure &obj)
{
    std::cout << "Cure : Copy Constractor Called"<< std::endl;
	*this = obj;
}
Cure &Cure::operator=(const Cure &obj)
{
	this->type = obj.type;
	return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure : Destractor Called" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}