/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:56:15 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/25 19:56:32 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
	std::string idea[100];
	public:
		Brain();
		Brain(const Brain&);
		Brain& operator=(const Brain&);
		~Brain();
		const std :: string* getIdea() const;
		void setIdea(std :: string);
};
#endif