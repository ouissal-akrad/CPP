/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:13:04 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 18:55:39 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FlagTrap.hpp"

FragTrap :: FragTrap()
{
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std :: cout << "constructeur sans parametre  FrapTrap" << std ::endl;
}
FragTrap :: FragTrap(std:: string name)
{
	this->name = name;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std :: cout << "constructeur avec parametre  FrapTrap" << std ::endl;
}
FragTrap :: FragTrap(const FragTrap& copy)
{
	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	std :: cout << "constructeur de copy  FrapTrap" << std ::endl;
}
FragTrap FragTrap :: operator=(const FragTrap& c)
{
	this->name = c.name;
	this->Hit_points = c.Hit_points;
	this->Energy_points = c.Energy_points;
	this->Attack_damage = c.Attack_damage;
	return(*this);
}
void FragTrap :: highFivesGuys(void)
{
	std :: cout << "une demande de high fives" << std::endl;
}

void FragTrap :: attack(const std::string& target)
{
	if(Energy_points > 0 && Hit_points > 0)
	{
		Energy_points -= 1;
		std::cout << "FragTrap : " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	}
	else 
		std :: cout << "ni de vie et ni d energie" << std ::endl;
}

FragTrap :: ~FragTrap()
{
	std :: cout << "destructeur FrapTrap" << std ::endl;
}