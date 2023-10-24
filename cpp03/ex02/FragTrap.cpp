/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:10:12 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/24 19:46:48 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap : Default Constructor Called" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
}
FragTrap::FragTrap(std::string Name)
	: ClapTrap(Name)
{
	this->name = Name;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap : Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	this->name = obj.name;
	this->Hit_points = obj.Hit_points;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	std::cout << "FragTrap : Copy Constructor Called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	this->name = obj.getName();
	this->Energy_points = obj.getEnergy_points();
	this->Hit_points = obj.getHit_points();
	this->Attack_damage = obj.getAttack_damage();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : Destructor Called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (Energy_points > 0 && Hit_points > 0)
	{
		Energy_points--;
		std::cout << "FragTrap : " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	}
	else
		std ::cout << "No life or energy." << std ::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : " << this->name << " brings happiness by giving high fives to everyone!" << std::endl;
}