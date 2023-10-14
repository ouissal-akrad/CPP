/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:17:47 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 20:42:13 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

HumanB::HumanB(std::string Name)
{
    name = Name;
    weapon = NULL;
}

void HumanB::attack()
{
    std::cout << name << " attacks";
    if(weapon)
        std::cout << " with their " << weapon->getType();
    std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    weapon = &Weapon;
}