/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:35:10 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 15:55:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const int numAnimals = 6;
	Animal *animals[numAnimals];

	for (int i = 0; i < numAnimals; ++i)
	{
		if (i < numAnimals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Use the animals
	for (int i = 0; i < numAnimals; ++i)
		animals[i]->makeSound();

	// Delete the animals
	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];

	return (0);
}