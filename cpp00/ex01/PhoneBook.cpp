/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:34:24 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/11 18:56:17 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"

void	PhoneBook::Store(void)
{
	this->data[i % 8].AddContact();
	this->i++;
}

void PhoneBook::Print() 
{
    for (int index = 0; index < 8; index++) 
	{
        Contact contact = data[index];
        std::cout << "Contact " << index + 1 << ":\n";
        std::cout << "First Name: " << contact.f_name << std::endl;
        std::cout << "Last Name: " << contact.l_name << std::endl;
        std::cout << "Nickname: " << contact.n_name << std::endl;
        std::cout << "Phone Number: " << contact.p_number << std::endl;
        std::cout << "Darkest Secret: " << contact.darkest << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}

void PhoneBook::DisplayContactList() {
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "  Index    |  First Name  |  Last Name   |  Nickname   " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    for (int index = 0; index < 8; index++) 
    {
        const Contact contact = data[index];
        std::cout << "  " << index + 1 << std::string(10 - std::to_string(index + 1).length(), ' ') << "|";

        std::string t_fname = contact.f_name.substr(0, 10);
        std::string t_lname = contact.l_name.substr(0, 10);
        std::string t_nmane = contact.n_name.substr(0, 10);
        if (contact.f_name.length() > 10) 
            t_fname[9] = '.';
        if (contact.l_name.length() > 10)
            t_lname[9] = '.';
        if (contact.n_name.length() > 10)
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

    if (index >= 1 && index <= 8) {
        const Contact contact = data[index - 1];
        std::cout << "Contact Information:" << std::endl;
        std::cout << "First Name: " << contact.f_name << std::endl;
        std::cout << "Last Name: " << contact.l_name << std::endl;
        std::cout << "Nickname: " << contact.n_name << std::endl;
        std::cout << "Phone Number: " << contact.p_number << std::endl;
        std::cout << "Darkest Secret: " << contact.darkest << std::endl;
    } else 
    {
        std::cout << "Invalid index. Please enter a valid index between 1 and 8." << std::endl;
    }
}