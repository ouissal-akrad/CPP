/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:34:24 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/16 20:00:55 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->i = 0;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::Store() 
{
    static int i = 0;
    this->data[i % 8].AddContact();
    if(this->i < 8)
        this->i++;
    i++;
}

void PhoneBook::DisplayContactList() {
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "  Index   |  F_Name  |  L_Name  | Nickname |  " << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int index = 0; index < i; index++) 
    {
        Contact contact = data[index];
        std::cout << std::setw(10) << index + 1 << "|";

        std::string first_name = contact.GetFirstName();
        std::string last_name = contact.GetLastName();
        std::string nickname = contact.GetNickname();

        if (first_name.length() > 10)
            first_name = first_name.substr(0, 9) + ".";
        if (last_name.length() > 10)
            last_name = last_name.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << std::setw(10) << first_name << "|";
        std::cout << std::setw(10) << last_name << "|";
        std::cout << std::setw(10) << nickname << "|" << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
}

void PhoneBook::Search() 
{
    DisplayContactList();
    std::string index_str;
    int index;
    std::cout << "Enter the index of the contact you want to display: ";
    if (!std::getline(std::cin, index_str))
    {
        std::cin.clear();
        std::clearerr(stdin);
        std::cout << std::endl;
    }
    if (index_str.length() == 1)
    {
        index = index_str[0] - 48;
        if(index <= i && index > 0)
        {
            Contact contact = data[index - 1];
            std::cout << "Contact Information:" << std::endl;
            std::cout << "First Name: " << contact.GetFirstName() << std::endl;  
            std::cout << "Last Name: " << contact.GetLastName() << std::endl;    
            std::cout << "Nickname: " << contact.GetNickname() << std::endl;    
            std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;  
            std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << std::endl;  
        }
        else 
            std::cout << "Invalid index. Please enter a valid index between 1 and " << i << "." << std::endl;
    } 
    else 
            std::cout << "Invalid index. Please enter a valid index between 1 and " << i << "." << std::endl;
    std::cin.clear();
}
