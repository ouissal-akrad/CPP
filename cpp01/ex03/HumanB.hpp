/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:17:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 21:02:04 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include"Weapon.hpp"

class HumanB{
    private :
    Weapon *weapon;
    std::string name;
    public :
    HumanB(std::string Name);
    void attack();
    void setWeapon(Weapon &Weapon);
};

#endif