/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:43:05 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:50:05 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT
#define WRONG_CAT
#include<iostream>
#include"WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
    std::string getType() const;
    WrongCat();
    WrongCat(const WrongCat&);
    WrongCat& operator=(const WrongCat&);
    ~WrongCat();
    void makeSound() const;
};

#endif