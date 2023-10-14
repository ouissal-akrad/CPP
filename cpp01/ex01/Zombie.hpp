/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:06:58 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 19:15:05 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class Zombie
{
  private :
    std::string name;
public:
    Zombie();
    ~Zombie();
    void announce();
    void setName(std::string name);  
};

Zombie* zombieHorde(int N, std::string name);
#endif