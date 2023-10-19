/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:49:11 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/19 18:12:30 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
		std::string name;
		int 		Hit_points;
		int 		Energy_points;
		int 		Attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap&);
		~ClapTrap();
		ClapTrap &operator =(const ClapTrap&);
		void setName(std::string);
		std::string getName();
		int getHit_points();
		int getEnergy_points();
		int getAttack_damage();	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif