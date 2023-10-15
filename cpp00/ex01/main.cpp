/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:58:11 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 23:15:46 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"

int main()
{
    std::string cmd;
    Contact contact;
    PhoneBook phonebook;

    while (true)
    {
        std::cout << "Please enter your command: (ADD, SEARCH, EXIT)" << std::endl;
        if (!std::getline(std::cin, cmd))
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
        if (cmd == "ADD")
            phonebook.Store();
        else if (cmd == "SEARCH")
            phonebook.Search();
        else if (cmd == "EXIT")
            exit(0);
        else
            std::cout << "Sorry, our PhoneBook accepts only (ADD, SEARCH, EXIT)" << std::endl;
    }
    return 0;
}