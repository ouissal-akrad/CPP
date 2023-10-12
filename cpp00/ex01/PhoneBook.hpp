/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:58:13 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/12 19:25:46 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include"Contact.hpp"

class PhoneBook {
private :
    Contact data[8];
    int		i;
public:
    PhoneBook();
    ~PhoneBook();
    void Store();
    void Print();
    void Search();
     void DisplayContactList();
};


#endif