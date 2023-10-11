/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:58:17 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/11 16:58:18 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; ++j)
			av[i][j] = toupper(av[i][j]);
		std::cout << av[i];
	}
	std::cout << std::endl;
	return (0);
}