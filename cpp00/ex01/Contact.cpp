/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:01:24 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 22:51:40 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::AddContact()
{
	std::cout << "the first name please" << std::endl;
	while (true)
	{
		if (std::getline(std::cin, this->f_name).eof())
		{
			std::cout << "Failed to read input for the first name." << std::endl;
			continue ;
		}
		if (!this->f_name.empty())
			break ;
		else
			std::cout << "First name cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the last name please" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, this->l_name))
		{
			std::cout << "Failed to read input for the last name." << std::endl;
			continue ;
		}
		if (!this->l_name.empty())
			break ;
		else
			std::cout << "Last name cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the nickname please" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, this->n_name))
		{
			std::cout << "Failed to read input for the nickname." << std::endl;
			continue ;
		}
		if (!this->n_name.empty())
			break ;
		else
			std::cout << "Nickname cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the darkest please" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, this->darkest))
		{
			std::cout << "Failed to read input for the darkest." << std::endl;
			continue ;
		}
		if (!this->darkest.empty())
			break ;
		else
			std::cout << "Darkest cannot be empty. Please enter again." << std::endl;
	}
	std::cout << "the phone number please" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, this->p_number))
		{
			std::cout << "Failed to read input for the phone number." << std::endl;
			continue ;
		}
		if (!this->p_number.empty())
			break ;
		else
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
