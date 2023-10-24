/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:10:02 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/24 14:16:11 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScavTrap.hpp"

int main()
{
    ScavTrap a("Ouissal");
    ScavTrap b("Noone");
    
    a.attack(b.getName());
    b.takeDamage(10);
    b.attack(a.getName());
    a.takeDamage(b.getAttack_damage());
    a.guardGate();
    b.guardGate();
    a.beRepaired(4);
    b.beRepaired(4);
}