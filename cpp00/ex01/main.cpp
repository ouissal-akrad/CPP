/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:58:11 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/11 19:31:55 by ouakrad          ###   ########.fr       */
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
        std::cout << "Please enter your command: (ADD, SEARCH, PRINT,EXIT)" << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD")
			phonebook.Store();
        else if (cmd == "PRINT")
            phonebook.Print();
        else if (cmd == "SEARCH")
            phonebook.Search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Sorry, our PhoneBook accepts only (ADD, SEARCH, EXIT, PRINT)" << std::endl;
    }
    return 0;
}
