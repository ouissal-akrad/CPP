/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:46:44 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 21:02:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type)
{
    type = Type;
}

std::string const &Weapon::getType()
{
    return(type);
}

void Weapon::setType(std::string Type)
{
    type = Type;
}