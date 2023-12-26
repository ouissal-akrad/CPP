/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:44:56 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/26 23:50:44 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"Teta", "World", "C++", "Templates"};

    iter(intArray, 5, fun<int>);
    std::cout << "-------------------" << std::endl;
    iter(doubleArray, 5, fun<double>);
    std::cout << "-------------------" << std::endl;
    iter(stringArray, 4, fun<std::string>);
    return 0;
}