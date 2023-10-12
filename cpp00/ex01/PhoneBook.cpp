/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:34:24 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/12 18:23:09 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::Store()
{
    i = 0;
    if (i < 8)
    {
        data[i].AddContact();
        i++;
    }
}

void PhoneBook::Print() 
{
    for (int index = 0; index < 8; index++) 
    {
        Contact contact = data[index];
        std::cout << "Contact " << index + 1 << ":\n";
        std::cout << "First Name: " << contact.GetFirstName() << std::endl;  // Use getters
        std::cout << "Last Name: " << contact.GetLastName() << std::endl;    // Use getters
        std::cout << "Nickname: " << contact.GetNickname() << std::endl;    // Use getters
        std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;  // Use getters
        std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << std::endl;  // Use getters
        std::cout << "-------------------------" << std::endl;
    }
}

void PhoneBook::DisplayContactList() {
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "  Index    |  First Name  |  Last Name   |  Nickname   " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    for (int index = 0; index < i; index++) 
    {
        const Contact contact = data[index];
        std::cout << "  " << index + 1 << std::string(10 - std::to_string(index + 1).length(), ' ') << "|";

        std::string t_fname = contact.GetFirstName().substr(0, 10);  // Use getters
        std::string t_lname = contact.GetLastName().substr(0, 10);    // Use getters
        std::string t_nmane = contact.GetNickname().substr(0, 10);    // Use getters
        if (contact.GetFirstName().length() > 10) 
            t_fname[9] = '.';
        if (contact.GetLastName().length() > 10)
            t_lname[9] = '.';
        if (contact.GetNickname().length() > 10)
            t_nmane[9] = '.';
        std::cout << t_fname << std::string(10 - t_fname.length(), ' ') << "|";
        std::cout << t_lname << std::string(10 - t_lname.length(), ' ') << "|";
        std::cout << t_nmane << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
}

void PhoneBook::Search() {
    DisplayContactList();
    int index;
    std::cout << "Enter the index of the contact you want to display: ";
    std::cin >> index;

    if (index >= 1 && index <= i) {
        const Contact contact = data[index - 1];
        std::cout << "Contact Information:" << std::endl;
        std::cout << "First Name: " << contact.GetFirstName() << std::endl;  // Use getters
        std::cout << "Last Name: " << contact.GetLastName() << std::endl;    // Use getters
        std::cout << "Nickname: " << contact.GetNickname() << std::endl;    // Use getters
        std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;  // Use getters
        std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << std::endl;  // Use getters
    } else 
    {
        std::cout << "Invalid index. Please enter a valid index between 1 and " << i << "." << std::endl;
    }
}
