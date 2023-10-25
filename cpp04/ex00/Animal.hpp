/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:21:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:38:00 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>

class Animal
{
  protected :
    std::string type;
  public :
    void setType(std::string);
    std::string getType() const;
    Animal();
    Animal(std::string Type);
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual void makeSound() const;
    virtual ~Animal();
};

#endif