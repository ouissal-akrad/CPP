/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:35:10 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 20:30:27 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	WrongAnimal *wr = new WrongCat();
	std::cout << "***************************************" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wr->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	wr->makeSound();
	std::cout << "***************************************" << std::endl;
	delete meta;
	delete i;
	delete j;
	return (0);
}