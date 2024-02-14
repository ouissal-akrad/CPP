/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:55 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/14 19:37:22 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
void l()
{
    system("leaks btc");
}
int main(int ac, char **av)
{
    atexit(l);
    if (ac != 2)
    {
        std::cout << "Error: Your program must take a file as an argument" << std::endl;
        return 1;
    }
    try
    {
        go(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}