/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:00 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 23:26:29 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 0)
        return(NULL);
    Zombie *zombie = new Zombie[N];
    for(int i = 0;i < N; i++)
    {
        zombie[i].setName(name);
        zombie[i].announce();
    }
    return(zombie);
}