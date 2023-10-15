/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 23:26:52 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(5, "Test");
    Zombie *zombies1 = zombieHorde(0, "Test");
    delete[] zombies;
    delete[] zombies1;
}

