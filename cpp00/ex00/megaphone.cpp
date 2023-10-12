/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:58:17 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/12 21:34:19 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string arg = av[i]; 
			for (size_t j = 0; j < arg.length(); j++)
				arg[j] = std::toupper(arg[j]); 
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return (0);
}
