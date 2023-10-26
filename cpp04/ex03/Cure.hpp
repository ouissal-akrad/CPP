/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:00:54 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 18:46:24 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &obj);
        Cure &operator=(const Cure &obj);
        ~Cure();
        AMateria *clone() const;
        void use(ICharacter& target);
};
#endif