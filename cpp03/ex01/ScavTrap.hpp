/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:58:44 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/19 20:42:44 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#defide SCAVTRAP_HPP
class ScavTrap : public ClapTrap
{
    protected :
      void guardGate();
    public :
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap &obj);
        ScavTrap &operator=(const ScavTrap &obj);
        void attack(const std::string& target) ;
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate();
};
#endif