/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:13:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/22 18:53:38 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAPCLAP_HPP
#define FRAPCLAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std:: string name);
		FragTrap(const FragTrap&);
		FragTrap operator=(const FragTrap&);
		void highFivesGuys(void);
		void attack(const std::string& target);
		~FragTrap();
};

#endif