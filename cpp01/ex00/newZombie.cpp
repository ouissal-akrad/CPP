/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:31:21 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 22:31:00 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *newZombie = new Zombie;
    newZombie->setName(name);
    return (newZombie);
}