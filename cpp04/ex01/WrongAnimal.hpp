/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:26 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 21:06:48 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include<iostream>

class WrongAnimal
{
  protected :
    std::string type;
  public :
    void setType(std::string);
    std::string getType() const;
    WrongAnimal();
    WrongAnimal(std::string Type);
    WrongAnimal(const WrongAnimal&);
    WrongAnimal& operator=(const WrongAnimal&);
    void makeSound() const;
    ~WrongAnimal();
};

#endif
