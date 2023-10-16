/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:05:02 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/16 17:44:45 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>
class Weapon 
{
    private:
        std::string type;
    public:
    std::string const &getType();
    Weapon(std::string Type);
    void setType(std::string Type);
};
#endif