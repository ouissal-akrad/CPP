/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:20:25 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/15 19:31:05 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"harl.hpp"

void Harl :: info(void)
{
    std :: cout << "[INFO] " << std :: endl;
    std :: cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std ::endl;
}
void Harl :: debug(void)
{
    std :: cout << "[DEBUG] " << std :: endl;
    std :: cout << "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std ::endl;
}   
void Harl :: warning(void )
{
    std :: cout << "[WARNING] " << std :: endl;
    std :: cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std ::endl;
}
void Harl :: error(void )
{
    std :: cout << "[ERROR] " << std :: endl;
    std :: cout <<"This is unacceptable ! I want to speak to the manager now." << std ::endl;
}

void Harl :: complain(std::string level)
{
    std ::string str[] ={"DEBUG","INFO","WARNING","ERROR"};
    int option = -1;
    int i;
    for(i = 0;i < 4; i++)
    {
        if (level == str[i])
            option = i;
    }
    void(Harl::*logFunctions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
        if (option >= 0 && option < 4)
            (this->*logFunctions[option])();
    // switch (option)
    // {
    //     case 0:
    //         debug();
    //         break;
    //      case 1:
    //         info();
    //         break;
    //     case 2:
    //         warning();
    //         break;
    //     case 3:
    //         error();
    //         break;
    // }
}