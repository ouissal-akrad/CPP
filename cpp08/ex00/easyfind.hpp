/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:41:30 by ouakrad           #+#    #+#             */
/*   Updated: 2024/01/02 19:38:19 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <exception>

template<typename T>
bool easyfind(T &container,int value)
{
	if(std::find(container.begin(),container.end(),value) != container.end())
	{
		std::cout << "value exist in container "<< std::endl;
		return(true);
	}
	throw std::exception();
}
#endif

