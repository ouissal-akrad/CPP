/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:20:36 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 19:31:19 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *ptr = &name;
    std::string &ref = name;

    std::cout << "The memory address of the string variable : " << &name << std::endl;
    std::cout << "The memory address held by ptr : " << ptr << std::endl;
    std::cout << "The memory address held by reference : " << &ref << std::endl;
    
    std::cout << "-------------------------------------------------------------" << std::endl;
    
    std::cout << "The value of the string : " <<name << std::endl;
    std::cout << "The value of the ponter : " << *ptr << std::endl;
    std::cout << "The value of the reference : " <<ref << std::endl;
}