/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:43:03 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/24 14:22:26 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap : Default Constructor Called" << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->name = name;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
	std :: cout <<  "ScavTrap : " << name << " : Constructor with parameters called" << std ::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	this->name = obj.name;
	this->Hit_points = obj.Hit_points;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	std::cout << "ScavTrap : Copy Constructor Called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	this->name = obj.getName();
	this->Energy_points = obj.getEnergy_points();
	this->Hit_points = obj.getHit_points();
	this->Attack_damage = obj.getAttack_damage();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if(Energy_points > 0 && Hit_points > 0)
	{
		Energy_points--;
		std::cout << "ScavTrap : " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	}
	else 
		std :: cout << "Dead!" << std ::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap : " << this->name << " takes " << amount << " damage";
	this->Hit_points -= amount;
	if (this->Hit_points <= 0)
	{
		std::cout << "Dead!" << std::endl;
		this->Hit_points = 0;
	}
	else
		std::cout << " but remains standing." << std::endl;
}
void ScavTrap::guardGate()
{
	if (this->Energy_points <= 0 || this->Hit_points <= 0)
		return ;
	std::cout << "ScavTrap : " <<this->name << " : unlocked the Keeper mode. Guard on!" << std::endl;
}
