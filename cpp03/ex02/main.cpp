/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:10:02 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/23 19:14:41 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"

int main()
{
    FragTrap a("player1");
    FragTrap b("player2");
    ClapTrap c("player3");
    a.attack(b.getName());
    b.takeDamage(10);
    b.attack(a.getName());
    a.takeDamage(b.getAttack_damage());
    c.attack(a.getName());
    a.beRepaired(4);
    b.beRepaired(4);
    a.highFivesGuys();
    b.highFivesGuys();
}