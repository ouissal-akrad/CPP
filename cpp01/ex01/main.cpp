/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/16 17:29:48 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(5, "Test");
    Zombie *zombies1 = zombieHorde(-5, "Test");
    delete[] zombies;
    delete[] zombies1;
}

