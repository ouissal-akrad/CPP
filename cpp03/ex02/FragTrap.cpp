/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:10:12 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/23 18:25:13 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap : Default Constructor Called" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
}
FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
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
	if (this != &obj)
	{
		this->name = obj.getName();
		this->Energy_points = obj.getEnergy_points();
		this->Hit_points = obj.getHit_points();
		this->Attack_damage = obj.getAttack_damage();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : Destructor Called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->Energy_points <= 0 || this->Hit_points <= 0)
		return ;
	std::cout << "FragTrap : " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
	this->Energy_points -= 1;
}

void FragTrap::highFivesGuys(void) 
{
  std::cout << "FragTrap : " << this->name << " brings happiness by giving high fives to everyone!" << std::endl;
}