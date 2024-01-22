/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:55 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/18 16:15:25 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
	{
		std::cout << "Error: Your program must take a file as argument" << std::endl;
		return (1);
	}
	BitcoinExchange exchange;
	exchange.go(av[1]);
	return (0);
}