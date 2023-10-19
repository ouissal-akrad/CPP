/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:10:02 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/19 18:26:59 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

int main()
{
    ClapTrap a("Ouissal");
    ClapTrap b("Aissam");

    a.attack(b.getName());
    b.takeDamage(10);
    b.attack(a.getName());
    a.takeDamage(b.getAttack_damage());
    a.beRepaired(4);
    b.beRepaired(4);
}