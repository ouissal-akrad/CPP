/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:10:42 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 17:18:36 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

Serializer::Serializer()
{
}
uintptr_t Serializer::serialize(t_data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}
t_data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<t_data *>(raw);
}
Serializer::~Serializer()
{
}

