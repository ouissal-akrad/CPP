/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:39:53 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 16:55:51 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria : Default Constractor Called"<< std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
    std::cout << "AMateria : Copy Constractor Called"<< std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria : Destractor Called"<< std::endl;
}
AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
}
AMateria &AMateria::operator=(const AMateria &obj)
{

	this->type = obj.type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}