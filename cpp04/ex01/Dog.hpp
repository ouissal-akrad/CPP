/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:51 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 20:32:08 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include"Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    private:
        Brain *brain;
    public:
    std::string getType() const;
    Dog();
    Dog(const Dog&);
    Dog& operator=(const Dog&);
    ~Dog();
    void makeSound() const;
    const Brain* getBrain() const;
	void setBrain(Brain);
};


#endif