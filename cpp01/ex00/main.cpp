/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:15:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/16 17:08:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

int main() 
{
    //Normal Zombie
    Zombie zombie;
    zombie.setName("Ouissal");
    zombie.announce();
    //*new
    Zombie* zombie1 = newZombie("DynamicZombie1");
    Zombie* zombie2 = newZombie("DynamicZombie2");

    zombie1->announce();
    zombie2->announce();
    //random
    randomChump("random one");

    delete zombie1;
    delete zombie2;

    return(0);
}
