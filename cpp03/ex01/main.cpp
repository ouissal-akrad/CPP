/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:10:02 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/24 19:10:07 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScavTrap.hpp"

int main()
{
    ClapTrap a("player1");
    ScavTrap b("player2");
    
    a.attack(b.getName());
    b.takeDamage(a.getAttack_damage());
    b.attack(a.getName());
    a.takeDamage(b.getAttack_damage());
    // a.guardGate();
    a.beRepaired(4);
    b.beRepaired(4);
    b.guardGate();
}