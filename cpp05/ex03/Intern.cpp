/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:35:49 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/19 12:51:17 by ouakrad          ###   ########.fr       */
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

	form = nullptr;
	choix = -1;
	std::string str[3] = {"Robotomy request", "Shrubbery Creation",
		"Presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == str[i])
		{
			choix = i;
			break ;
		}
	}
	switch (choix)
	{
	case 0:
		form = new ShrubberyCreationForm(target);
		break ;
	case 1:
		form = new RobotomyRequestForm(target);
		break ;
	case 2:
		form = new PresidentialPardonForm(target);
		break ;
	default:
		throw std::invalid_argument("Invalid form name");
	}
	if (form)
	{
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	return (form);
}

Intern::~Intern()
{
	// std::cout << "Destractor Called"<< std::endl;
}