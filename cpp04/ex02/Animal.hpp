/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:21:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 21:24:55 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
    virtual std::string getType() const;
    virtual void makeSound() const = 0;
    virtual ~AAnimal();
};
