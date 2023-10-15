/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:59:42 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 23:31:59 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : weapon(Weapon), name(Name){}

 

void HumanA::attack()
{
    std::cout << name << " attacks" << " with their " << weapon.getType() << std::endl;
}