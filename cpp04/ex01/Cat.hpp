/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:43:23 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 20:34:46 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include"Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
    private:
        Brain *brain;
    public:
    std::string getType() const;
    Cat();
    Cat(const Cat&);
    Cat& operator=(const Cat&);
    ~Cat();
    void makeSound() const;
    Brain* getBrain() const;
	void setBrain(Brain);
};

#endif