/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:19:29 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/26 18:54:58 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Character : public ICharacter
{
  private:
	std::string name;
	AMateria *slots[4];

  public:
	Character();
	Character(const std::string &name);
	Character(const Character &obj);
	Character &operator=(const Character &obj);
	~Character();
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};
#endif