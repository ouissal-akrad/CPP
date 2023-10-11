/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:00:57 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/11 17:57:08 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Contact.hpp"

void Contact::AddContact()
{
    std::cout << "the first name please" << std::endl;
    std::cin >> this->f_name;
    std::cout << "the last name please" << std::endl;
    std::cin >> this->l_name;
    std::cout << "the nickname nickname please" << std::endl;
    std::cin >> this->n_name;
    std::cout << "the phone number please" << std::endl;
    std::cin >> this->p_number;
    std::cout << "the darkest please" << std::endl;
	std::cin >> this->darkest;
}
