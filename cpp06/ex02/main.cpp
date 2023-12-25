/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:32:19 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 21:42:10 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"

int main() 
{
    std::srand(static_cast<unsigned>(std::time(NULL)));
    Base *randomInstance = generate();
    identify(randomInstance);
    identify(*randomInstance);
    delete randomInstance;
    return 0;
}