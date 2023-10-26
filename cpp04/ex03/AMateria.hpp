/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:28:15 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 18:41:49 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AIMATERIA_HPP
#define AIMATERIA_HPP
#include<iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &obj);
        AMateria &operator=(const AMateria &obj);
        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual ~AMateria();
        virtual void use(ICharacter& target);

};
#endif