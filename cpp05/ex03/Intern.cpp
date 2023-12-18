/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:35:49 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/18 11:28:41 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Default Constractor Called"<< std::endl;
}
Intern::Intern(const Intern &copy)
{
	*this = copy;
	// std::cout << "Copy Constractor Called"<< std::endl;
}
Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm	*form;
	int		choix;

	std::string str[3] = {"Robotomy request", "Shrubbery Creation",
		"Presidential pardon"};
	form = nullptr;
	choix = -1;
	for (int i = 0; i < 3; i++)
	{
		if (name == str[i])
		{
			choix = i;
			break ;
		}
	}
	if (choix == 0)
	{
		form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else if (choix == 1)
	{
		form = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else if (choix == 2)
	{
		form = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else
	{
		throw std::invalid_argument("Invalid form name");
	}
	return (form);
}
Intern::~Intern()
{
	// std::cout << "Destractor Called"<< std::endl;
}