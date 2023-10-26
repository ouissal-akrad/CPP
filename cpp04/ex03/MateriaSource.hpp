/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:18:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 18:18:59 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *slots[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &obj);
        MateriaSource &operator=(const MateriaSource &obj);
        ~MateriaSource();
        void learnMateria(AMateria *M);
        AMateria *createMateria(std::string const &type);
};
#endif