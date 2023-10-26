/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:19:23 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 20:38:17 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
    // std::cout << "MateriaSurce : Default Constractor Called"<< std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
    // std::cout << "MateriaSurce : Copy Constractor Called"<< std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.slots[i])
			this->slots[i] = obj.slots[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) 
    {
        if (slots[i])
            delete slots[i];
    }
}


void MateriaSource::learnMateria(AMateria *M)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->slots[i] && M)
        {
            this->slots[i] = M;
            break;
        }
    }
}


AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (this->slots[i] && this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	return (NULL);
}