/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:15:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/13 22:38:11 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

int main() 
{
    // Zombie zombie1;
    // //zombie
    // zombie1.setName("Ouissal");
    // zombie1.announce();
    // //random
    // zombie1.randomChump("random one");
    //*new
    Zombie* zombie1 = newZombie("DynamicZombie1");
    Zombie* zombie2 = newZombie("DynamicZombie2");

    zombie1->announce();
    zombie2->announce();

    delete zombie1;
    delete zombie2;
    return(0);
}
