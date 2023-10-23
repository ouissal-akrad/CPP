/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:58 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/23 18:08:13 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
	std :: cout << "Default constructor called" << std ::endl;
}

ClapTrap :: ClapTrap(std::string name)
{
	this->name = name;
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
	std :: cout << name << " Constructor with parameters called" << std ::endl;
}

ClapTrap :: ClapTrap(const ClapTrap &copy)
{
	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	std::cout << "Copy constructor called" << std ::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	this->name = claptrap.name;
	this->Hit_points = claptrap.Hit_points;
	this->Energy_points = claptrap.Energy_points;
	this->Attack_damage = claptrap.Attack_damage;
	return(*this);
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

std::string ClapTrap::getName() const
{
    return(this->name);
}
int ClapTrap::getHit_points() const
{
    return(this->Hit_points);
}
int ClapTrap::getEnergy_points() const
{
    return(this->Energy_points);
}
int ClapTrap::getAttack_damage() const
{
    return(this->Attack_damage);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std ::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if(Energy_points > 0 && Hit_points > 0)
	{
		Energy_points--;
		std::cout << "ClapTrap: " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	}
	else 
		std :: cout << "No life or energy." << std ::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_points > (int)amount)
		Hit_points -= amount;
	else
		Hit_points = 0;
	std::cout << "Loser!" <<  std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Hit_points += amount;
        Energy_points -= 1;
        std::cout << "ClapTrap " << this->name << " drinks a healing potion and restores " << amount << " HitPoints." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is unable to recover. No life or energy." << std::endl;
}

