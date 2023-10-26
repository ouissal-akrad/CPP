/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:21:18 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 18:54:49 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->name = "Default";
	std::cout << "Charachter : Default Constractor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}
Character::Character(const std::string &name)
{
	std::cout << "Charachter : copy Constractor Called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(const Character &obj)
{
	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	this->name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		delete this->slots[i];
		this->slots[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (obj.slots[i])
			this->slots[i] = obj.slots[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Charachter : Destractor Called" << std::endl;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->slots[idx] = NULL;
	else
		std::cout << "Invalid idx" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && slots[idx])
		this->slots[idx]->use(target);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] == nullptr)
		{
			slots[i] = m;
			return ;
		}
	}
}
