/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:56:47 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:58:10 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : Default Constractor Called" << std::endl;
}
Brain::Brain(const Brain& brain)
{
	*this = brain;
	std::cout << "Brain : Constractor with parameters Called" << std::endl;
}
Brain& Brain::operator=(const Brain& brain)
{
	for(int i = 0 ; i < 100; i++)
		this->idea[i] = brain.idea[i];	
	return (*this);
}
Brain::~Brain()
{
	std::cout << "Brain : Copy Constractor Called" << std::endl;
}

const std :: string* Brain :: getIdea() const
{
	return(this->idea);
}
void Brain :: setIdea(std :: string idea)
{
	for(int i = 0; i < 100; i++)
		this->idea[i] = idea;
}