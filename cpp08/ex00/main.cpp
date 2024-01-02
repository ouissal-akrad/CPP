/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:11:09 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/02 19:08:02 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
int main()
{
	std::vector<int> v;
	for(int i = 0 ; i < 10;i++)
		v.push_back(i);
	try
    {
		easyfind(v,2);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}