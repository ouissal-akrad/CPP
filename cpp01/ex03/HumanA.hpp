/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:59:39 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/16 17:49:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include"Weapon.hpp"

class HumanA{
    private :
        Weapon &weapon;
        std::string name;

    public :
        HumanA(std::string Name, Weapon &Weapon);
        void attack();
};

#endif