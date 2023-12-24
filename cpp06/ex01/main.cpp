/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:10:47 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 17:29:00 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    t_data *originalData = new t_data;
    originalData->a = 42;
    originalData->c = 'A';
    
    uintptr_t serializedPointer = Serializer::serialize(originalData);

    t_data *deserializedData = Serializer::deserialize(serializedPointer);

    if (deserializedData == originalData)
    {
        std::cout << "Serialization and Deserialization Successful!" << std::endl;
        std::cout << "Original Data Address: " << originalData << std::endl;
        std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
        std::cout << "Original Data: a = " << originalData->a << ", c = " << originalData->c << std::endl;
    }
    else
        std::cout << "Serialization and Deserialization Failed!" << std::endl;
    delete originalData;
    return 0;
}