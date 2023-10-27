/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:21:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/27 14:19:20 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include<iostream>

class AAnimal
{
  protected :
    std::string type;
  public :
    void setType(std::string);
    AAnimal();
    AAnimal(std::string Type);
    AAnimal(const AAnimal&);
    AAnimal& operator=(const AAnimal&);
    virtual std::string getType() const = 0;
    virtual void makeSound() const = 0;
    virtual ~AAnimal();
};
#endif