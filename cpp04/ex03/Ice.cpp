/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:57:00 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 20:35:04 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice()
{
    this->type = "ice";
    // std::cout << "Ice : Default Constractor Called"<< std::endl;
}
Ice::Ice(const Ice &obj)
{
    // std::cout << "Ice : Copy Constractor Called"<< std::endl;
	*this = obj;
}
Ice &Ice::operator=(const Ice &obj)
{
	this->type = obj.type;
	return (*this);
}

Ice::~Ice()
{
    // std::cout << "Ice : Destractor Called" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}