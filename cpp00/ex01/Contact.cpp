/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:00:57 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/13 16:13:19 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::AddContact()
{
    std::cout << "the first name please" << std::endl;
    std::getline(std::cin, this->f_name);
    std::cout << "the last name please" << std::endl;
    std::getline(std::cin, this->l_name);
    std::cout << "the nickname please" << std::endl;
    std::getline(std::cin, this->n_name);
    std::cout << "the darkest please" << std::endl;
    std::getline(std::cin, this->darkest);
    std::cout << "the phone number please" << std::endl;
    std::getline(std::cin, this->p_number);
}

std::string Contact::GetFirstName() const
{
    return f_name;
}

std::string Contact::GetLastName() const
{
    return l_name;
}

std::string Contact::GetNickname() const
{
    return n_name;
}

std::string Contact::GetPhoneNumber() const
{
    return p_number;
}

std::string Contact::GetDarkestSecret() const
{
    return darkest;
}
