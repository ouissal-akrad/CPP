/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:15:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 22:32:42 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

int main() 
{
    
    Zombie zombie;
    zombie.setName("Ouissal");
    zombie.announce();
    //random
    randomChump("random one");
    //*new
    Zombie* zombie1 = newZombie("DynamicZombie1");
    Zombie* zombie2 = newZombie("DynamicZombie2");

    zombie1->announce();
    zombie2->announce();

    delete zombie2;
    delete zombie1;

    
    return(0);
}
