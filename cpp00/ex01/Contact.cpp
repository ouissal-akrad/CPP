/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:01:24 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 20:12:02 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::AddContact()
{
	std::cout << "the first name please" << std::endl;
	while (true)
	{
        if (!std::getline(std::cin, this->f_name))
            exit(0);
		if (!this->f_name.empty())
			break ;
		std::cout << "First name cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the last name please" << std::endl;
	while (true)
	{
        if (!std::getline(std::cin, this->l_name))
            exit(0);
		if (!this->l_name.empty())
			break ;
		std::cout << "Last name cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the nickname please" << std::endl;
	while (true)
	{
        if (!std::getline(std::cin, this->n_name))
            exit(0);
		if (!this->n_name.empty())
			break ;
		std::cout << "Nickname cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the darkest please" << std::endl;
	while (true)
	{
         if (!std::getline(std::cin, this->darkest))
            exit(0);
		if (!this->darkest.empty())
			break ;
		std::cout << "Darkest cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the phone number please" << std::endl;
	while (true)
	{
        if (!std::getline(std::cin, this->p_number))
            exit(0);
		if (!this->p_number.empty())
			break ;
		std::cout << "Phone number cannot be empty. Please enter again." << std::endl;
	}
}

std::string Contact::GetFirstName() const
{
	return (f_name);
}

std::string Contact::GetLastName() const
{
	return (l_name);
}

std::string Contact::GetNickname() const
{
	return (n_name);
}

std::string Contact::GetPhoneNumber() const
{
	return (p_number);
}

std::string Contact::GetDarkestSecret() const
{
	return (darkest);
}
