/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:44:20 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:44:51 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat : Default Constractor Called"<< std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    this->type = copy.type;
    std::cout << "WrongCat : Copy Constractor Called"<< std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    this->type = obj.type;
    return(*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat : Mew Mew" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat : Destractor Called" << std::endl;
}